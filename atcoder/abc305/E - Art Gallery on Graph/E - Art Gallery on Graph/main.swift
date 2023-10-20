import Foundation

func readInts() -> [Int] { readLine()!.split(separator: " ").map({ Int($0)! }) }
func read1() -> Int { Int(readLine()!)! }
func read2() -> (Int, Int) { let line = readInts(); return (line[0], line[1]) }
func read3() -> (Int, Int, Int) { let line = readInts(); return (line[0], line[1], line[2]) }
func readGrid(_ h: Int) -> [[Int]] { Array(0..<h).map({ _ in readInts() }) }

func readStrings() -> [String] { readLine()!.split(separator: " ").map({ String($0) }) }

func printBool(_ b: Bool) { print(b ? "Yes" : "No") }
func printArray<T>(_ a: [T]) { for v in a { print(v)} }
func printInline<T: CustomStringConvertible>(_ a: [T]) { print(a.map({ $0.description }).joined(separator: " ")) }

extension Character { var ascii: Int { Int(asciiValue!) } }
func ord(_ c: Character) -> Int { Int(c.asciiValue!) }
func - (lhs: Character, rhs: Character) -> Int { Int(lhs.asciiValue!) - Int(rhs.asciiValue!) }
func array2(_ m: Int, _ n: Int, _ v: Int = 0) -> [[Int]] { Array(repeating: Array(repeating: v, count: n), count: m) }
func array(_ n: Int, _ v: Int = 0) -> [Int] { Array(repeating: v, count: n) }
func partialSum(_ a: [Int]) -> [Int] { var s = 0, r = [0]; for x in a { s += x; r.append(s) }; return r }


func solve() -> [Int] {
    let (n, m, k) = read3()
    var g = Array(repeating: [Int](), count: n + 1)
    for _ in 0..<m {
        let (a, b) = read2()
        g[a].append(b)
        g[b].append(a)
    }
    var ks = [(Int, Int)]()
    var mp = [Int: (Int, Int)]() // p: h, idx
    for i in 0..<k {
        let (p, h) = read2()
        ks.append((p, h))
        mp[p] = (h, i)
    }
    ks.sort { $0.1 > $1.1 }
    var vis = Array(repeating: false, count: n + 1)
    var visk = Array(repeating: false, count: k)
    for i in 0..<k {
        if visk[i] { continue }
        visk[i] = true
        vis[ks[i].0] = true
        var q = [ks[i]]
        while !q.isEmpty {
            let (x, h) = q.removeFirst()
//            print("x: \(x), \(h)")
            var nh = h - 1
            for y in g[x] {
                if vis[y] { continue }
                vis[y] = true
                if mp[y] != nil { // another guard
                    let (yh, yi) = mp[y]!
                    if !visk[yi] {
                        visk[yi] = true
                        nh = max(nh, yh)
                    }
                }
                if nh > 0 {
                    q.append((y, nh))
                }
            }
        }
    }
//    print(vis, visk)
    var res = [Int]()
    for i in 1...n {
        if vis[i] {
            res.append(i)
        }
    }
    return res
}

//print(solve())
//printBool(solve())
//printArray(solve())
let res = solve()
print(res.count)
printInline(res)

