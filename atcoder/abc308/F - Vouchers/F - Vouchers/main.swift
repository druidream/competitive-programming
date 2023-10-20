import Foundation

func readInts() -> [Int] { readLine()!.split(separator: " ").map({ Int($0)! }) }
func read1() -> Int { Int(readLine()!)! }
func read2() -> (Int, Int) { let line = readInts(); return (line[0], line[1]) }
func read3() -> (Int, Int, Int) { let line = readInts(); return (line[0], line[1], line[2]) }
func readGrid(_ h: Int) -> [[Int]] { Array(0..<h).map({ _ in readInts() }) }

func readStrings() -> [String] { readLine()!.split(separator: " ").map({ String($0) }) }

func printBool(_ b: Bool) { print(b ? "Yes" : "No") }
func printArray<T>(_ a: [T]) { for v in a { print(v)} }
func printInline<T: CustomStringConvertible>(_ a: [T]) { print(a.map({ $0.description }).joined(separator: " ")) }

extension Character { var ascii: Int { Int(asciiValue!) } }
func ord(_ c: Character) -> Int { Int(c.asciiValue!) }
func - (lhs: Character, rhs: Character) -> Int { Int(lhs.asciiValue!) - Int(rhs.asciiValue!) }
func array2(_ m: Int, _ n: Int, _ v: Int = 0) -> [[Int]] { Array(repeating: Array(repeating: v, count: n), count: m) }
func array(_ n: Int, _ v: Int = 0) -> [Int] { Array(repeating: v, count: n) }
func partialSum(_ a: [Int]) -> [Int] { var s = 0, r = [0]; for x in a { s += x; r.append(s) }; return r }

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


func solve() -> Int {
    let (n, m) = read2()
    var P = readInts()
    let L = readInts()
    let D = readInts()
    P.sort()
    var a = [(Int, Int)]()
    for i in 0..<m {
        a.append((L[i], D[i]))
    }
    a.sort { $0.0 == $1.0 ? $0.1 > $1.1 : $0.0 < $1.0 }
    var pq = PriorityQueue<(Int, Int)>(sort: {
        $0.1 > $1.1
    })
    var ans = 0
    var j = 0
    for i in 0..<n {
        while j < m && a[j].0 <= P[i] {
            pq.insert(a[j])
            j += 1
        }
        if pq.isEmpty { ans += P[i] }
        else {
            let (_, d) = pq.remove()!
            ans += P[i] - d
        }
    }
    return ans
}

print(solve())
//printBool(solve())
//printArray(solve())
//printInline(solve())

