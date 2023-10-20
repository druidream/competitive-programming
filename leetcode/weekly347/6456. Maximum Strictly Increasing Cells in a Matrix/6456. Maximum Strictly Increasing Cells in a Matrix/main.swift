class Solution {
    func maxIncreasingCells(_ mat: [[Int]]) -> Int {
        let m = mat.count, n = mat[0].count
        if m == 1 && n == 1 { return 1 }
        var rows = [PriorityQueue<(Int, Int, Int)>]()
        var cols = [PriorityQueue<(Int, Int, Int)>]()
        for i in 0..<m {
            let row = mat[i].enumerated().map { ($0.1, i, $0.0) }
            rows.append(PriorityQueue(sort: { $0.0 < $1.0 }, items: row))
        }
        for j in 0..<n {
            var col = [(Int, Int, Int)]()
            for i in 0..<m {
                col.append((mat[i][j], i, j))
            }
            cols.append(PriorityQueue(sort: { $0.0 < $1.0 }, items: col))
        }
        var pq = PriorityQueue<(Int, Int, Int)>(sort: { $0.0 < $1.0 })
        for i in 0..<m {
            for j in 0..<n {
                pq.insert((mat[i][j], i, j))
            }
        }
        var g = Array(repeating: Array(repeating: 1, count: n), count: m)
        var ans = 1, lastVal = Int.min, lastRow = -1, lastCol = -1
        while !pq.isEmpty {
            let (u, r, c) = pq.remove()!
            if u != lastVal || r != lastRow {
                while !rows[r].isEmpty && rows[r].peek()!.0 <= u {
                    rows[r].remove()
                }
                if !rows[r].isEmpty {

                    let nxt = rows[r].peek()!.0
                    while !rows[r].isEmpty && rows[r].peek()!.0 == nxt {
                        let (v, i, j) = rows[r].remove()!
                        if v > u {
                            g[i][j] = max(g[i][j], g[r][c] + 1)
                            ans = max(ans, g[i][j])
    //                        break
                        }
                    }
                }
            }
//            print(u, r, c, g)

            if u != lastVal || c != lastCol {

                while !cols[c].isEmpty && cols[c].peek()!.0 <= u {
                    cols[c].remove()
                }
                if !cols[c].isEmpty {
                    let nxt = cols[c].peek()!.0
                    while !cols[c].isEmpty && cols[c].peek()!.0 == nxt {
                        let (v, i, j) = cols[c].remove()!
                        if v > u {
                            g[i][j] = max(g[i][j], g[r][c] + 1)
                            ans = max(ans, g[i][j])
    //                        break
                        }
                    }
                }
            }
            lastVal = u
            lastRow = r
            lastCol = c
        }
        return ans
    }
}

struct PriorityQueue<T> {
    private var items = [T]()
    private var sort: (T, T) -> Bool
    init(sort: @escaping (T, T) -> Bool, items: [T] = []) {
        self.sort = sort
        for item in items {
            insert(item)
        }
    }

    var isEmpty: Bool {
        items.isEmpty
    }

    var count: Int {
        items.count
    }

    func peek() -> T? {
        items.first
    }

    mutating func remove() -> T? {
        if isEmpty { return nil }
        items.swapAt(0, count - 1)
        defer {
            sink(from: 0)
        }
        return items.removeLast()
    }

    mutating func insert(_ item: T) {
        items.append(item)
        swim(from: count - 1)
    }

    //
    private func leftChildIndex(ofParentAt index: Int) -> Int {
        2 * index + 1
    }

    private func rightChildIndex(ofParentAt index: Int) -> Int {
        2 * index + 2
    }

    private func parentIndex(ofChildAt index: Int) -> Int {
        (index - 1) / 2
    }

    private mutating func sink(from index: Int) {
        var parent = index
        while true {
            let left = leftChildIndex(ofParentAt: parent)
            let right = rightChildIndex(ofParentAt: parent)
            var candidate = parent
            if left < count && sort(items[left], items[candidate]) {
                candidate = left
            }
            if right < count && sort(items[right], items[candidate]) {
                candidate = right
            }
            if candidate == parent {
                return
            }
            items.swapAt(parent, candidate)
            parent = candidate
        }
    }

    private mutating func swim(from index: Int) {
        var child = index
        var parent = parentIndex(ofChildAt: child)
        while child > 0 && sort(items[child], items[parent]) {
            items.swapAt(child, parent)
            child = parent
            parent = parentIndex(ofChildAt: child)
        }
    }
}

//print(Solution().maxIncreasingCells([[3,1],[3,4]]))
print(Solution().maxIncreasingCells([[3,1,6],[-9,5,7]]))
//print(Solution().maxIncreasingCells([[-9,-9,1,-4,0,2]])) // 5
//print(Solution().maxIncreasingCells([[8,-9,4,7,-7,-9],[-1,6,-1,5,-2,-7]])) // 7
