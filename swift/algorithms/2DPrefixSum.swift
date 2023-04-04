class NumMatrix {
    var g: [[Int]]
    init(_ mat: [[Int]]) {
        let m = mat.count, n = mat[0].count
        g = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
        for i in 0..<m {
            for j in 0..<n {
                g[i + 1][j + 1] = g[i][j + 1] + g[i + 1][j] - g[i][j] + mat[i][j]
            }
        }
    }
    
    func sumRegion(_ row1: Int, _ col1: Int, _ row2: Int, _ col2: Int) -> Int {
        g[row2 + 1][col2 + 1] - g[row2 + 1][col1] - g[row1][col2 + 1] + g[row1][col1]
    }
}