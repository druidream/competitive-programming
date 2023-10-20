class Solution {
    let mod = Int(1e9 + 7)
    func ways(_ pizza: [String], _ k: Int) -> Int {
        var g = pizza.map { Array($0) }
        let n = g.count, m = g[0].count
        let ms = NumMatrix(g)
        var memo = Array(repeating: Array(repeating: Array(repeating: -1, count: m), count: n), count: k)
        func dfs(_ i: Int, _ r: Int, _ c: Int) -> Int {
            if i == 0 { return ms.query(r, c, n, m) > 0 ? 1 : 0 }
            // if r == n || c == m { return 0 }
            if memo[i][r][c] != -1 { return memo[i][r][c] }
            var res = 0
            for j2 in c + 1..<m {
                if ms.query(r, c, n, j2) > 0 {
                    res += dfs(i - 1, r, j2)
                }
            }
            for i2 in r + 1..<n {
                if ms.query(r, c, i2, m) > 0 {
                    res += dfs(i - 1, i2, c)
                }
            }
            res %= mod
            memo[i][r][c] = res
            return res
            // var found = false
            // for x in r..<n {
            //     if !found {
            //         for y in c..<m {
            //             if g[x][y] == "A" {
            //                 found = true
            //             }
            //         }
            //     }
            //     if found {
            //         res = (res + dfs(i - 1, x + 1, c)) % mod
            //     }
            // }
            // found = false
            // for y in c..<m {
            //     if !found {
            //         for x in r..<n {
            //             if g[x][y] == "A" {
            //                 found = true
            //             }
            //         }
            //     }
            //     if found {
            //         res = (res + dfs(i - 1, r, y + 1)) % mod
            //     }
            // }
            // memo[i][r][c] = res
            // return res
        }
        return dfs(k - 1, 0, 0)
    }
}

class NumMatrix {
    var g: [[Int]]
    init(_ mat: [[Character]]) {
        let m = mat.count, n = mat[0].count
        g = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
        for i in 0..<m {
            for j in 0..<n {
                let v = mat[i][j] == "A" ? 1 : 0
                g[i + 1][j + 1] = g[i][j + 1] + g[i + 1][j] - g[i][j] + v
            }
        }
    }
    
    func query(_ row1: Int, _ col1: Int, _ row2: Int, _ col2: Int) -> Int {
        g[row2][col2] - g[row2][col1] - g[row1][col2] + g[row1][col1]
    }
}

print(Solution().ways(["A..","AAA","..."], 3))
