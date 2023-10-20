class Solution {
    let inf = 0x3f3f3f3f
    func minimumJumps(_ forbidden: [Int], _ a: Int, _ b: Int, _ x: Int) -> Int {
        var memo = Array(repeating: inf, count: 4001)
        for num in forbidden {
            memo[num] = -1
        }
        func dfs(_ pos: Int) -> Int {
            if pos == x { return 0 }
            if memo[pos] != inf { return memo[pos] }
            let right = pos + a, left = pos - b
            var res = inf
            if right <= 4000 {
                let v = dfs(right)
                if v != -1 {
                    res = min(res, v + 1)
                }
            }
            if left > 0 {
                let v = dfs(left)
                if v != -1 {
                    res = min(res, v + 1)
                }
            }
            if res == inf { res = -1 }
            memo[pos] = res
            return res
        }
        return dfs(0)
    }
}

print(Solution().minimumJumps([1,6,2,14,5,17,4], 16, 9, 7))
