class Solution {
    static let primes: [Int] = {
        var res = [Int]()
        func isPrime(_ x: Int) -> Bool {
            for f in 2...x {
                if f * f > x { break }
                if x % f == 0 { return false }
            }
            return true
        }
        for x in 2...Int(1e5) {
            if isPrime(x) {
                res.append(x)
            }
        }
        return res
    }()
    func canTraverseAllPairs(_ nums: [Int]) -> Bool {
        let n = nums.count
        let m = Self.primes.count
        let mx = nums.max()!
        let uf = UnionFind(n)
        for f in Self.primes {
            if f > mx { break }
            var idx = [Int]()
            for i in 0..<n {
                if nums[i] % f == 0 {
                    idx.append(i)
                }
            }
            for i in 0..<idx.count {
                uf.union(idx[i], idx[0])
            }
        }
        return uf.groupCount == 1
    }
}

class UnionFind {
    private let n: Int
    private var id: [Int]
    private var sz: [Int]
    init(_ n: Int) {
        self.n = n
        id = Array(repeating: 0, count: n)
        sz = Array(repeating: 1, count: n)
        for i in 0..<n {
            id[i] = i
        }
    }
    func union(_ x: Int, _ y: Int) {
        let x = find(x), y = find(y)
        if x == y { return }
        if sz[x] < sz[y] {
            id[x] = y
            sz[y] += sz[x]
        } else {
            id[y] = x
            sz[x] += sz[y]
        }
    }
    func find(_ x: Int) -> Int {
        return x == id[x] ? x : find(id[x])
    }
    func isConnected(_ x: Int, _ y: Int) -> Bool {
        return find(x) == find(y)
    }
    var groupCount: Int {
        var set = Set<Int>()
        for i in 0..<n {
            set.insert(find(i))
        }
        return set.count
    }
}

print(Solution().canTraverseAllPairs([2,3,6]))
