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

let d4 = [1, 0, -1, 0, 1]
let S = Array("snuke")
func solve() -> Bool {
    let (h, w) = read2()
    var g = [[Character]]()
    for _ in 0..<h {
        g.append(Array(readLine()!))
    }
    if g[0][0] != "s" { return false }
    var q = [(Int, Int, Int)]() // i, j, idx
    var vis = array2(h, w)
    vis[0][0] = 1
    q.append((0, 0, 0))
    while !q.isEmpty {
        let (i, j, k) = q.removeFirst()
        for d in 0..<4 {
            let x = i + d4[d], y = j + d4[d + 1], idx = k + 1
            if x >= 0 && x < h && y >= 0 && y < w && vis[x][y] == 0 {
                if g[x][y] == S[idx % 5] {
                    vis[x][y] = 1
                    if x == h - 1 && y == w - 1 { return true }
                    q.append((x, y, idx))
                }
            }
        }
    }
    return false
}

//print(solve())
printBool(solve())
//printArray(solve())
//printInline(solve())

