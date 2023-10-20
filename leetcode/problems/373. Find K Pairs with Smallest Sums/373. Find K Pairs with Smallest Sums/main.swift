class Solution {
    // WA，思路不对, nums1 中的小数可能能和 nums2 中任意大数组成合法配对
    func kSmallestPairs(_ nums1: [Int], _ nums2: [Int], _ k: Int) -> [[Int]] {
        let n = nums1.count, m = nums2.count
        let k = min(k, m * n)
        var i = 0, j = 0
        while i < n && j < m {
            if (i + 1) * (j + 1) <= k {
                if j == m - 1 || nums1[i] < nums2[j] {
                    i += 1
                } else {
                    j += 1
                }
            } else {
                break
            }
        }
        print(i, j)
        let len1 = i + 1, len2 = j + 1
        var res = [[Int]]()
        for i in 0..<len1 {
            for j in 0..<len2 {
                res.append([nums1[i], nums2[j]])
            }
        }
//        let cnt = k - res.count
        var arr = [[Int]]()
        if len1 < n {
            for j in len2..<m {
                arr.append([nums1[len1], nums2[j]])
            }
        }
        if len2 < m {
            for i in len1..<n {
                arr.append([nums1[i], nums2[len2]])
            }
        }
        res += arr
        print(res)
        res.sort { $0[0] + $0[1] < $1[0] + $1[1] }
        
        return Array(res.prefix(k))
    }
}

print(Solution().kSmallestPairs([1,7,11], [2,4,6], 3))
