// https://www.youtube.com/watch?v=NBUwpGuqAzY
class Solution {
    func minOperations(_ s1: String, _ s2: String, _ x: Int) -> Int {
        let s = Array(s1), t = Array(s2), n = s.count
        var m = 0, nums = [0]
        for i in 0..<n {
            if s[i] != t[i] {
                m += 1
                nums.append(i)
            }
        }
        if m % 2 == 1 { return -1 }
        var f = Array(repeating: Array(repeating: Int.max / 2, count: 2), count: n + 1)
        f[0][0] = 0
        for i in 1...n {
            for u in 0...1 {
                if i - 2 >= 0 {
                    f[i][u] = min(f[i][u], f[i - 2][u] + nums[i] - nums[i - 1])
                }
                if u == 0 {
                    f[i][u] = min(f[i][u], f[i - 1][u + 1])
                } else {
                    f[i][u] = min(f[i][u], f[i - 1][u - 1] + x)
                }
            }
        }
        return f[n][0]
    }
}

print(Solution().minOperations("1100011000", "1100011000", 2))
