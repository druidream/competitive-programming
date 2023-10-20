class Solution {
    let mod = Int(1e9 + 7)
    func count(_ num1: String, _ num2: String, _ min_sum: Int, _ max_sum: Int) -> Int {
        func g(_ s: String) -> Int {
            let s = Array(s)
            let n = s.count
            var memo = Array(repeating: Array(repeating: Array(repeating: -1, count: 2), count: max_sum + 1), count: s.count)
            func dfs(_ cur: Int, _ sum: Int, _ isLimit: Int) -> Int {
//                print(cur, sum, isLimit)
                if cur == n {
                    return sum >= min_sum ? 1 : 0
                }
                if memo[cur][sum][isLimit] != -1 { return memo[cur][sum][isLimit] }
                var cnt = 0
                if isLimit == 1 {
                    let mx = Int(s[cur].asciiValue! - 48)
                    for d in 0...mx {
                        if sum + d > max_sum { break }
                        cnt = (cnt + dfs(cur + 1, sum + d, d == mx ? 1 : 0)) % mod
                    }
                } else {
                    for d in 0...9 {
                        if sum + d > max_sum { break }
                        cnt = (cnt + dfs(cur + 1, sum + d, 0)) % mod
                    }
                }
                memo[cur][sum][isLimit] = cnt
                return memo[cur][sum][isLimit]
            }
            let ans = dfs(0, 0, 1)
//            print(memo)
            return ans
        }
        var s1 = Array(num1).reversed().map { Int($0.asciiValue! - 48) }
        let carry = -1
        for i in 0..<s1.count {
            let v = s1[i] + carry
            if v >= 0 {
                s1[i] = v
                break
            } else {
                s1[i] = 9
            }
        }
        let ss1 = s1.reversed().map({ String($0) }).joined()
//        print(ss1)
        return (g(num2) - g(ss1) + mod) % mod
    }
}

//print(Solution().count("1", "12", 1, 8)) // 11
print(Solution().count("6312", "9416", 29, 30)) // 114
//print(Solution().count("1", "100", 9, 10)) // 114
