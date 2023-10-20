class Solution {
    func mctFromLeafValues(_ arr: [Int]) -> Int {
        let inf = 1 << 32
        let n = arr.count
        var f = Array(repeating: Array(repeating: (0, 0), count: n), count: n)
        func dfs(_ i: Int, _ j: Int) -> (Int, Int) {
            if i == j { return (0, arr[i])}
            if i + 1 == j {
                f[i][j] = (arr[i] * arr[j], max(arr[i], arr[j]))
                return f[i][j]
            }
            if f[i][j].1 > 0 { return f[i][j] }
            var sum = inf, mx = 0
            for k in stride(from: i, through: j - 1, by: 1) {
                let (lsum, lmax) = dfs(i, k)
                let (rsum, rmax) = dfs(k + 1, j)
                if lsum + rsum + lmax * rmax < sum {
                    sum = lsum + rsum + lmax * rmax
                    mx = max(lmax, rmax)
                }
            }
            f[i][j] = (sum, mx)
            return f[i][j]
        }
        return dfs(0, n - 1).0
    }
}

print(Solution().mctFromLeafValues([6, 2, 4]))
