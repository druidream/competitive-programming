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


func solve() {
    let (n, d) = read2()
    var arr = [(Int, Int)]()
    for i in 0..<n {
        arr.append(read2())
    }
    var g = Array(repeating: [Int](), count: n)
    for i in 0..<n {
        for j in 0..<i {
            let (a1, b1) = arr[i]
            let (a2, b2) = arr[j]
            if (a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2) <= d * d {
                g[i].append(j)
                g[j].append(i)
            }
        }
    }
    var q = [0]
    var vis = Array(repeating: false, count: n)
    vis[0] = true
    while !q.isEmpty {
        let i = q.removeFirst()
        for j in g[i] {
            if vis[j] { continue }
            vis[j] = true
            q.append(j)
        }
    }
    for v in vis {
        printBool(v)
    }
}
solve()
//print(solve())
//printBool(solve())
//printArray(solve())
//printInline(solve())

