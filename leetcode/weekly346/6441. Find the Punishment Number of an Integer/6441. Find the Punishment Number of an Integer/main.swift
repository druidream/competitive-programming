class Solution {
    func punishmentNumber(_ n: Int) -> Int {
        var ans = 0
        for x in 1...n {
            let s = Array(String(x * x)).map({ Int($0.asciiValue! - 48) })
            
            func dfs(_ cur: Int, _ k: Int) -> Bool {
                if cur == s.count { return k == 0 }
                var v = 0
                for i in cur..<s.count {
                    v = v * 10 + s[i]
                    if v > k { break }
                    if dfs(i + 1, k - v) { return true }
                }
                return false
            }
            
            if dfs(0, x) {
//                print(x)
                ans += x * x
            }
        }
        return ans
    }
}

print(Solution().punishmentNumber(10))
