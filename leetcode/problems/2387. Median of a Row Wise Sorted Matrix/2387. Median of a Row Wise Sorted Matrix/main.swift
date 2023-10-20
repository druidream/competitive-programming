class Solution {
    func matrixMedian(_ grid: [[Int]]) -> Int {
        let n = grid.count, m = grid[0].count
        let k = n * m / 2 + 1
        // check, 判断 <= x 的元素是否「足够」k 个
        // true，也就是 cnt >= k，说明 <= x 的元素太多了，移动 hi
        // false，也就是 cnt < k，说明 <= x 的元素少了，移动 lo
        // 当 x 刚好是中位数 mid 时，<= x 的元素一定 >= n / 2 + 1
        // 当 x 是 mid - 1 时，<= x 的元素一定 <= n / 2
        // 为什么 k 取 n * m / 2 + 1 ???
        func check(_ x: Int) -> Bool {
            var cnt = 0
            for i in 0..<n {
                var lo = 0, hi = m - 1
                while lo <= hi {
                    let mid = (lo + hi) / 2
                    if grid[i][mid] > x {
                        hi = mid - 1
                    } else {
                        lo = mid + 1
                    }
                }
                cnt += lo
            }
//            print(x, cnt)
            return cnt >= k
        }
        var lo = 1, hi = Int(1e6)
        while lo <= hi {
            let mid = (lo + hi) / 2
            if check(mid) {
                hi = mid - 1
            } else {
                lo = mid + 1
            }
        }
        return lo
    }
}

class Solution1 {
    func matrixMedian(_ grid: [[Int]]) -> Int {
        let n = grid.count, m = grid[0].count
        let k = n * m / 2 + 1
        // check, 判断 <= x 的元素是否「不足」k 个
        // false，也就是 cnt >= k，说明 <= x 的元素太多了，移动 hi
        // true，也就是 cnt < k，说明 <= x 的元素少了，移动 lo
        // 当 x 刚好是中位数 mid 时，<= x 的元素一定 >= n / 2 + 1
        // 当 x 是 mid - 1 时，<= x 的元素一定 <= n / 2
        // 为什么 k 取 n * m / 2 ???
        func check(_ x: Int) -> Bool {
            var cnt = 0
            for i in 0..<n {
                var lo = 0, hi = m - 1
                while lo <= hi {
                    let mid = (lo + hi) / 2
                    if grid[i][mid] > x {
                        hi = mid - 1
                    } else {
                        lo = mid + 1
                    }
                }
                cnt += lo
            }
            let ans = cnt < k
//             print(x, cnt, k, ans)
            return ans
        }
        var lo = 1, hi = Int(1e6)
        while lo <= hi {
            let mid = (lo + hi) / 2
            if check(mid) {
                lo = mid + 1
            } else {
                hi = mid - 1
            }
        }
        return lo
    }
}

print(Solution1().matrixMedian([[1,1,2],[2,3,3],[1,3,4]]))
