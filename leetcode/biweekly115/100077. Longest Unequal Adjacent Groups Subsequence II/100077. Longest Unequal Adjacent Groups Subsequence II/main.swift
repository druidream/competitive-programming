//class Solution {
//    func getWordsInLongestSubsequence1(_ n: Int, _ words: [String], _ groups: [Int]) -> [String] {
//        var g = Array(repeating: [Int](), count: n)
//        func dis(_ s: String, _ t: String) -> Bool {
//            let tc = Array(t)
//            var cnt = 0
//            for (i, c) in s.enumerated() {
//                if c != tc[i] {
//                    cnt += 1
//                    if cnt > 1 { return false }
//                }
//            }
//            return cnt == 1
//        }
//        for i in 0..<n {
//            for j in i + 1..<n {
//                if words[i].count != words[j].count { continue }
//                if groups[i] == groups[j] { continue }
//                if !dis(words[i], words[j]) { continue }
//                g[i].append(j)
//                g[j].append(i)
//            }
//        }
//        // print(g)
//        func dfs(_ x: Int, _ p: Int) -> Int {
//            var res = 0
//            for y in g[x] {
//                if y == p { continue }
//                res = max(res, dfs(y, x) + 1)
//            }
//            return res
//        }
//        func dfs2(_ x: Int, _ p: Int) -> [String] {
//            var res = [String]()
//            for y in g[x] {
//                if y == p { continue }
//                let arr = dfs2(y, x)
//                if arr.count > res.count {
//                    res = arr
//                }
//            }
//            res.append(words[x])
//            return res
//        }
//        var ans = 0, arr = [String]()
//        for i in 0..<n {
//            let len = dfs(i, -1)
//            if len > ans {
//                ans = len
//                arr = dfs2(i, -1)
//            }
//        }
//        return arr
//    }
//}
//class Solution {
//    func getWordsInLongestSubsequence(_ n: Int, _ words: [String], _ groups: [Int]) -> [String] {
//        let uf = UnionFind(n)
//        func dis(_ s: String, _ t: String) -> Bool {
//            let tc = Array(t)
//            var cnt = 0
//            for (i, c) in s.enumerated() {
//                if c != tc[i] {
//                    cnt += 1
//                    if cnt > 1 { return false }
//                }
//            }
//            return cnt == 1
//        }
//        for i in 0..<n {
//            for j in i + 1..<n {
//                if words[i].count != words[j].count { continue }
//                if groups[i] == groups[j] { continue }
//                if !dis(words[i], words[j]) { continue }
//                uf.union(i, j)
//            }
//        }
//        var g = Array(repeating: [Int](), count: n)
//        for i in 0..<n {
//            g[uf.find(i)].append(i)
//        }
//        func maxPath(_ a: [Int]) -> [String] {
//            let m = a.count
//            func bfs(_ i: Int, _ j: Int) -> [String] {
//                var pa = Array(repeating: -1, count: n)
//                var vis = Array(repeating: false, count: n)
//                var q = [(Int, Int)]()
//                q.append((i, -1))
//                q.append((j, -1))
//                var res = [Int]()
//                while !q.isEmpty {
//                    let old = q
//                    let cnt = q.count
//                    for _ in 0..<cnt {
//                        let (x, p) = q.removeFirst()
//                        for y in g[x] {
//                            if y == p { continue }
//                            if vis[y] { continue }
//                            vis[y] = true
//                            pa[y] = x
//                            q.append((y, x))
//                        }
//                    }
//                    if q.isEmpty {
//                        res = [old[0].0]
//                        var i = old[0].0
//                        while pa[i] != -1 {
//                            i = pa[i]
//                            res.append(i)
//                        }
//                        i = old[0].0
//                        
//                        while pa[i] != -1 {
//                            i = pa[i]
//                            res.insert(i, at: 0)
//                        }
//                        break
//                    }
//                }
//                return res.map { words[$0] }
//            }
//            var res = [String]()
//            for i in 0..<m {
//                for j in i + 1..<m {
//                    let arr = bfs(i, j)
//                    if arr.count > res.count {
//                        res = arr
//                    }
//                }
//            }
//            return res
//        }
//        var res = [String]()
//        for i in 0..<n {
//            if g[i].count < 2 { continue }
//            print(g[i])
////            let arr = maxPath(g[i])
////            if arr.count > res.count {
////                res = arr
////            }
//        }
//        return res
//    }
//}
//
//class UnionFind {
//    private let n: Int
//    private var id: [Int]
//    private var sz: [Int]
//    init(_ n: Int) {
//        self.n = n
//        id = Array(repeating: 0, count: n)
//        sz = Array(repeating: 1, count: n)
//        for i in 0..<n {
//            id[i] = i
//        }
//    }
//    func union(_ x: Int, _ y: Int) {
//        let x = find(x), y = find(y)
//        if x == y { return }
//        if sz[x] < sz[y] {
//            id[x] = y
//            sz[y] += sz[x]
//        } else {
//            id[y] = x
//            sz[x] += sz[y]
//        }
//    }
//    func find(_ x: Int) -> Int {
//        return x == id[x] ? x : find(id[x])
//    }
//    func isConnected(_ x: Int, _ y: Int) -> Bool {
//        return find(x) == find(y)
//    }
//    var groupCount: Int {
//        var set = Set<Int>()
//        for i in 0..<n {
//            set.insert(find(i))
//        }
//        return set.count
//    }
//}

class Solution {
    func getWordsInLongestSubsequence(_ n: Int, _ words: [String], _ groups: [Int]) -> [String] {
        var res = [Int]()
        var g = Array(repeating: [Int](), count: n)
        func dis(_ s: String, _ t: String) -> Bool {
            let tc = Array(t)
            var cnt = 0
            for (i, c) in s.enumerated() {
                if c != tc[i] {
                   cnt += 1
                   if cnt > 1 { return false }
                }
            }
            return cnt == 1
        }
        func check(_ i: Int, _ j: Int) -> Bool {
            if words[i].count != words[j].count { return false }
            if groups[i] == groups[j] { return false }
            if !dis(words[i], words[j]) { return false }
            return true
        }
        for i in 0..<n {
            for j in i + 1..<n {
                if check(i, j) {
                    g[i].append(j)
                    g[j].append(i)
                }
            }
        }
        print(g)
        func bfs(_ i: Int, _ j: Int) -> [Int] {
            var pa = Array(repeating: -1, count: n)
            var vis = Array(repeating: false, count: n)
            var q = [(Int, Int)]()
            q.append((i, -1))
            q.append((j, -1))
            vis[i] = true
            vis[j] = true
            var res = [Int]()
            func dfs(_ cur: Int, _ x: Int, _ y: Int) -> [Int] {
                if cur == x { return [x] }
                if cur == y { return [y] }
                var parts = [[Int]]()
                for nxt in g[cur] {
                    let arr = dfs(nxt, x, y)
                    if arr.isEmpty { continue }
                    parts.append(arr)
                }
                if parts.isEmpty { return [] }
                if parts.count == 1 { return parts[0] }
                if parts.count == 2 {
                    res =  parts[0].reversed() + [cur] + parts[1]
                }
                return []
            }
            while !q.isEmpty {
                print(q)
                let old = q
                let cnt = q.count
                for _ in 0..<cnt {
                    let (x, p) = q.removeFirst()
                    for y in g[x] {
                        if y == p { continue }
                        if vis[y] { continue }
                        vis[y] = true
                        pa[y] = x
                        q.append((y, x))
                    }
                }
                if q.isEmpty {
                    dfs(old[0].0, i, j)
                    return res
                }
            }
            return []
        }
        for i in 0..<n {
            for j in i + 1..<n {
                let arr = bfs(i, j)
                if arr.count > res.count {
                    res = arr
                }
            }
        }
        return res.map { words[$0] }
    }
}

print(Solution().getWordsInLongestSubsequence(3, ["bab","dab","cab"], [1,2,2]))
//print(Solution().getWordsInLongestSubsequence(4, ["a","b","c","d"], [1,2,3,4]))
