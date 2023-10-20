class Solution {
    func evolutionaryRecord(_ parents: [Int]) -> String {
        let n = parents.count
        var g = Array(repeating: [Int](), count: n)
        for i in 0..<n {
            let p = parents[i]
            if p == -1 { continue }
            g[p].append(i)
        }
        func dfs(_ x: Int) -> String {
            var res = [Character]()
            var arr = [String]()
            for y in g[x] {
                arr.append("0" + dfs(y) + "1")
            }
            arr.sort(by: { $0 < $1 })
            for cs in arr {
                res += cs
            }
            return String(res)
        }
        var res = Array(dfs(0))
        while !res.isEmpty && res[res.count - 1] == "1" {
            res.removeLast()
        }
        return String(res)
    }
}

print(Solution().evolutionaryRecord([-1]))
