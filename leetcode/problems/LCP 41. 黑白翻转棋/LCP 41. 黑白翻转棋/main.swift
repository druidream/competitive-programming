class Solution {
    let dx = [-1,0,0,1,-1,-1,1,1]
    let dy = [0,1,-1,0,-1,1,-1,1]
    func flipChess(_ chessboard: [String]) -> Int {
        let g = chessboard.map { Array($0) }
        let n = g.count, m = g[0].count
        var ans = 0
        // func f(_ g: [[Character]], _ i: Int, _ j: Int) -> Int {
        //     var g = g
        //     var res = 0
        //     func flip(_ d: Int) -> Int {
        //         var x = i, y = j
        //         var sum = 0
        //         while true {
        //             x += dx[d]
        //             y += dy[d]
        //             if x < 0 && x == n && y < 0 && y == m { break }
        //             if g[x][y] == "." { break }
        //         }
        //         var ok = false
        //         while x != i {
        //             x -= dx[d]
        //             y -= dy[d]
        //             if g[x][y] == "O" && ok {
        //                 g[x][y] = "X"
        //                 sum += 1 + f(g, x, y)
        //             }
        //             if g[x][y] == "X" {
        //                 ok = true
        //             }
        //         }
        //         return sum
        //     }
        //     for d in 0..<8 {
        //         res += flip(d)
        //     }
        //     return res
        // }
        func check(_ g: [[Character]], _ x: Int, _ y: Int, _ di: Int, _ dj: Int) -> Bool {
            var x = x + di, y = y + dj
            while x >= 0 && x < n && y >= 0 && y < m {
                if g[x][y] == "X" {
                    return true
                } else if g[x][y] == "." {
                    return false
                }
                x += di
                y += dj
            }
            return false
        }
        func bfs(_ g: [[Character]], _ i: Int, _ j: Int) -> Int {
            var g = g
            var cnt = 0
            var q = [(Int, Int)]()
            q.append((i, j))
            g[i][j] = "X"
            while !q.isEmpty {
                let (u, v) = q.removeFirst()
                for d in 0..<8 {
                    if check(g, u, v, dx[d], dy[d]) {
                        var x = u + dx[d], y = v + dy[d]
                        while g[x][y] != "X" {
                            q.append((x, y))
                            g[x][y] = "X"
                            x += dx[d]
                            y += dy[d]
                            cnt += 1
                        }
                    }
                }
            }
            return cnt
        }
        for i in 0..<n {
            for j in 0..<m {
                if g[i][j] == "." {
                    ans = max(ans, bfs(g, i, j))
                }
            }
        }
        return ans
    }
}


print(Solution().flipChess(["....X.","....X.","XOOO..","......","......"]))
