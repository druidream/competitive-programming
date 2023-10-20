class Solution {
    let mod = Int(1e9 + 7)
    func specialPerm(_ nums: [Int]) -> Int {
        let n = nums.count, m = 1 << n - 1
        var g = Array(repeating: [Int](), count: n)
        for i in 0..<n {
            for j in i + 1..<n {
                if nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0 {
                    g[i].append(j)
                    g[j].append(i)
                }
            }
        }
        var memo = Array(repeating: Array(repeating: Array(repeating: -1, count: 1 << n), count: n), count: n)
        func dfs(_ cur: Int, _ i: Int, _ s: Int) -> Int {
//            print(cur, i, s)
            if s == m {
                return 1
            }
            if memo[cur][i][s] != -1 { return memo[cur][i][s] }
            var res = 0
            for j in g[i] {
                if (s >> j) & 1 == 0 {
                    res += dfs(cur + 1, j, s | (1 << j))
                }
            }
            memo[cur][i][s] = res
            return res
        }
        var ans = 0
        for i in 0..<n {
            ans = (ans + dfs(0, i, 1 << i)) % mod
        }
        return ans
    }
}

print(Solution().specialPerm([2 ,3, 6]))
