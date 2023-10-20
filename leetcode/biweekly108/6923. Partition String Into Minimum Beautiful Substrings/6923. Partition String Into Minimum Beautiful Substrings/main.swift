class Solution {
    let INF = 0x3f3f3f3f
    func minimumBeautifulSubstrings(_ s: String) -> Int {
        let n = s.count
        var s = s.map { Int(String($0))! }
        var memo = Array(repeating: INF, count: n)
        func check(_ l: Int, _ r: Int) -> Bool {
            if s[l] == 0 { return false }
            var v = 0
            for i in (l...r).reversed() {
                v |= s[i] << (r - i)
            }
//            print(l, r, v)
            while v > 1 && v % 5 == 0 {
                v /= 5
            }
            return v == 1
        }
        func dfs(_ i: Int) -> Int {
            if i == n { return 0 }
            if memo[i] != INF { return memo[i] }
            var res = INF
            for j in i..<n {
                if check(i, j) {
                    let v = dfs(j + 1)
//                    print("x", i, j, v)
                    if v != INF {
                        res = min(res, 1 + v)
                    }
                }
            }
            memo[i] = res
            return res
        }
//        print(memo)
        let ans = dfs(0)
        return ans == INF ? -1 : ans
    }
}

//print(Solution().minimumBeautifulSubstrings("1011"))
print(Solution().minimumBeautifulSubstrings("111"))
