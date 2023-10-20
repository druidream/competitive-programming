func optimalPoint(magic: [Int], dist: [Int]) -> Int {
    let n = magic.count
    var f = magic
    for i in 0..<n {
        f[i] -= dist[i]
    }
    print(f)
    var sum = 0, start = 0
    for i in 0..<n * 2 {
        sum += f[i % n]
        print(i, sum, start)
        while sum < 0 && start <= min(i, n - 1) {
            sum -= f[start]
            start += 1
        }
        if start == n { return -1 }
        if i - start == n - 1 {
            return start
        }
    }
    return -1
}

print(optimalPoint(magic: [8,4,1,9], dist: [10,9,3,5]))
