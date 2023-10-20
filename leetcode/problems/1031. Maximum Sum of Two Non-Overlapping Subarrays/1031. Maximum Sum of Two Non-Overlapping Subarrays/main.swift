class Solution {
    func maxSumTwoNoOverlap(_ nums: [Int], _ firstLen: Int, _ secondLen: Int) -> Int {
        let n = nums.count
        // [0, i] 范围内长度为 firstLen 的 max sum
        var f = Array(repeating: 0, count: n + 1)
        var g = Array(repeating: 0, count: n + 1)
        var sum = 0
        for i in 0..<n {
            sum += nums[i]
            if i - firstLen >= 0 {
                sum -= nums[i - firstLen]
            }
            f[i + 1] = max(f[i], sum)
        }
        sum = 0
        for i in (0..<n).reversed() {
            sum += nums[i]
            if i + firstLen <= n - 1 {
                sum -= nums[i + firstLen]
            }
            g[i] = max(g[i + 1], sum)
        }
        sum = 0
        var ans = 0
//        print(f)
//        print(g)
        for i in 0..<n {
            sum += nums[i]
            if i - secondLen >= 0 {
                sum -= nums[i - secondLen]
            }
            if i - secondLen + 1 >= 0 {
//                print(sum, i - secondLen + 1, i, max(f[i - secondLen + 1], g[i + 1]))
                ans = max(ans, sum + max(f[i - secondLen + 1], g[i + 1]))
            }
        }
        return ans
    }
}

print(Solution().maxSumTwoNoOverlap([0,6,5,2,2,5,1,9,4], 1, 2)) // 20
print(Solution().maxSumTwoNoOverlap([2,1,5,6,0,9,5,0,3,8], 4, 3)) // 31
print(Solution().maxSumTwoNoOverlap([1,0,3], 1, 2)) // 4
print(Solution().maxSumTwoNoOverlap([87,42,40,86,93,4,18,28,59,30,6,51,99,46,40,24,19,98,40,41], 1, 10))
import SwiftUI
