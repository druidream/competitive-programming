//class Solution {
//    func minExtraChar(_ s: String, _ dictionary: [String]) -> Int {
//        let s = Array(s), n = s.count, set = Set(dictionary)
//        var ans = 50
//        var path = 0
//        func backtrack(_ cur: Int) {
//            if cur == n {
//                return
//            }
//            var t = [Character]()
//            for j in cur..<n {
//                t.append(s[j])
//                if set.contains(String(t)) {
//                    path += t.count
//                    print(String(t))
//                    ans = min(ans, n - path)
//                    backtrack(j + 1)
//                    path -= t.count
//                } else {
//                    backtrack(j )
//                }
//            }
//        }
//        backtrack(0)
//        return ans
//    }
//}

class Solution {
    func minExtraChar(_ s: String, _ dictionary: [String]) -> Int {
        let s = Array(s), n = s.count, set = Set(dictionary)
        var f = Array(repeating: 0, count: n + 1)
        for i in 1...n {
            for j in 1...i {
                let t = String(s[j - 1...i - 1])
                if set.contains(t) {
                    print(t)
                    f[i] = max(f[i], f[j - 1] + t.count)
                } else {
                    f[i] = max(f[i], f[j - 1])
                }
            }
        }
//        print(f)
        return n - f[n]
    }
}

print(Solution().minExtraChar("leetscode", ["leet","code","leetcode"]))
