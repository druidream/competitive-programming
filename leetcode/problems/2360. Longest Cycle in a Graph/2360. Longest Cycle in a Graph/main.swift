class Solution {
    func longestCycle(_ g: [Int]) -> Int {
        let n = g.count
        var indeg = Array(repeating: 0, count: n)
        for x in g where x != -1 {
            indeg[x] += 1
        }
        var q = [Int]()
        for i in 0..<n where indeg[i] == 0 {
            q.append(i)
        }
        var vis = Array(repeating: false, count: n)
        while !q.isEmpty {
            let x = q.removeFirst()
            vis[x] = true
            let y = g[x]
            if y == -1 { continue }
            indeg[y] -= 1
            if indeg[y] == 0 {
                q.append(y)
            }
        }
        func bfs(_ x: Int) -> Int {
            var x = x, len = 0
            while x != -1 && !vis[x] {
                vis[x] = true
                x = g[x]
                len += 1
            }
            return len
        }
        var ans = -1
        for i in 0..<n where !vis[i] {
            ans = max(ans, bfs(i))
        }
        return ans
    }
}

print(Solution().longestCycle(<#T##g: [Int]##[Int]#>))
