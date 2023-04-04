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