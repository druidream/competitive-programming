class DisjointSet {
    var root: [Int] = []
    var rank: [Int] = []
    
    init (_ count: Int) {
        for i in 0..<count {
            root.append(i)
            rank.append(1)
        }
    }
    
    func find(_ x: Int) -> Int {
        if x != root[x] {
            root[x] = find(root[x])
        }
        return root[x]
    }
    
    func union(_ x: Int, _ y: Int) {
        let rootX = find(x)
        let rootY = find(y)
        if rootX == rootY { return }
        
        if rank[rootX] < rank[rootY] {
            root[rootX] = rootY
        } else if rank[rootX] > rank[rootY] {
            root[rootY] = rootX
        } else {
            root[rootY] = rootX
            rank[rootX] += 1
        }        
    }
}