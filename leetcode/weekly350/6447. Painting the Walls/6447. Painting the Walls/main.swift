class Solution {
    func paintWalls(_ cost: [Int], _ time: [Int]) -> Int {
        let n = cost.count
        var arr = [(Int, Int)]()
        for i in 0..<n {
            arr.append((cost[i], time[i]))
        }
        arr.sort { $0.0 < $1.0 }
        var f = Array(repeating: Array(repeating: Int(1e9), count: n + 1), count: n)
        for i in 0..<n {
            let t = min(n, arr[i].1 + 1)
            f[i][t] = arr[i].0
        }
        var ans = f[0][n]
        for i in 1..<n {
            for j in 0..<i {
                for k in 0...n {
                    let t = min(n, k + 1 + arr[i].1)
                    if f[j][k] + arr[i].0 < f[i][t] {
                        f[i][t] = f[j][k] + arr[i].0
                        if t == n {
                            ans = min(ans, f[i][t])
                        }
                    }
                }
            }
        }
//        print(arr)
//        print(f)
        return ans
    }
}

//print(Solution().paintWalls([8,7,5,15], [1,1,2,1])) // 12
//print(Solution().paintWalls([42,8,28,35,21,13,21,35], [2,1,1,1,2,1,1,2])) // 63
//print(Solution().paintWalls([2,2], [1,1]))
print(Solution().paintWalls([26,53,10,24,25,20,63,51], [1,1,1,1,2,2,2,1])) // 55


//[1,2,3,2]
//[1,2,3,2]
//[2,3,4,2]
//[1,1,1,1]
//[8,7,5,15]
//[1,1,2,1]
//[42,8,28,35,21,13,21,35]
//[2,1,1,1,2,1,1,2]
//[2,2]
//[1,1]
//[26,53,10,24,25,20,63,51]
//[1,1,1,1,2,2,2,1]
