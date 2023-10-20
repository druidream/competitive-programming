class Solution {
    static let table: [Int] = {
        var presum = Array(repeating: 0, count: 1001)
        for i in 1...1000 {
            let s = Array(String(i * i))
            let len = s.count
            func dfs(_ p: Int, _ sum: Int) -> Bool {
                if p == len { return sum == i }
                var x = 0
                for j in p..<len {
                    x = x * 10 + Int(s[j].asciiValue! - 48)
                    if dfs(j + 1, sum + x) {
                        return true
                    }
                }
                return false
            }
            presum[i] = presum[i - 1] + (dfs(0, 0) ? i * i : 0)
        }
        return presum
    }()
    func punishmentNumber(_ n: Int) -> Int {
        return Self.table[n]
    }
}

print(Solution().punishmentNumber(10))
