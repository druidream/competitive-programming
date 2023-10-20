class Solution {
    let d4 = [0, 1, 0, -1, 0]
    func uniquePathsIII(_ grid: [[Int]]) -> Int {
        let n = grid.count, m = grid[0].count
        var sx = 0, sy = 0
        var ex = 0, ey = 0
        var mask = 0
        for i in 0..<n {
            for j in 0..<m {
                if grid[i][j] == 1 {
                    sx = i; sy = j
                }
                if grid[i][j] == 2 {
                    ex = i; ey = j
                }
                if grid[i][j] == -1 {
                    mask |= 1 << (i * m + j)
                }
            }
        }
        var memo = Array(repeating: Array(repeating: -1, count: 1 << (n * m)), count: n * m)
        func dfs(_ x: Int, _ y: Int, _ s: Int) -> Int {
            if x == ex && y == ey {
                return s == 1 << (n * m) - 1 ? 1 : 0
            }
            let key = x * m + y
            if memo[key][s] != -1 { return memo[key][s] }
            var res = 0
            for d in 0..<4 {
                let r = x + d4[d], c = y + d4[d + 1]
                if r < 0 || r >= n || c < 0 || c >= m { continue }
                let key = r * m + c
                if s >> key == 1 { continue }
                res += dfs(r, c, s | (1 << key))
            }
            memo[key][s] = res
            return res
        }
        return dfs(sx, sy, mask)
    }
}

print(Solution().uniquePathsIII([[1,0,0,0],[0,0,0,0],[0,0,2,-1]]))
