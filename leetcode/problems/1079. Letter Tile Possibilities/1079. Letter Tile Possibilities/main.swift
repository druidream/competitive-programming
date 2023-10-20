class Solution {
    func numTilePossibilities(_ tiles: String) -> Int {
        let s = Array(tiles.sorted()), n = s.count
        var seen = Set<String>()
        var ans = 0
        for mask in 1..<1 << n {
            var t = ""
            for i in 0..<n {
                if (mask >> i) & 1 == 1 {
                    t.append(s[i])
                }
            }
            if seen.contains(t) {
                continue
            } else {
                seen.insert(t)
            }
            var mp = [Character: Int]()
            for c in t {
                mp[c, default: 0] += 1
            }
            var cnt = P(t.count)
            for v in mp.values {
                cnt /= P(v)
            }
            ans += cnt
        }
        return ans
    }
    func P(_ m: Int) -> Int {
        var ans = 1
        for x in 1...m {
            ans *= x
        }
        return ans
    }
}

print(Solution().numTilePossibilities("AAB"))
