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
    let (w, h) = read2()
    let n = read1()
    var pq = [(Int, Int)]()
    for i in 0..<n {
        pq.append(read2())
    }
    let A = read1()
    let a = readInts()
    let B = read1()
    let b = readInts()
    
    var f = Array(repeating: Array(repeating: 0, count: B + 1), count: A + 1)
    for (p, q) in pq {
        var x = 0, y = 0
        var lo = 0, hi = A - 1
        while lo <= hi {
            let mid = (lo + hi) / 2
            if a[mid] > p {
                hi = mid - 1
            } else {
                lo = mid + 1
            }
        }
        x = lo
        
        lo = 0; hi = B - 1
        while lo <= hi {
            let mid = (lo + hi) / 2
            if b[mid] > q {
                hi = mid - 1
            } else {
                lo = mid + 1
            }
        }
        y = lo
        f[x][y] += 1
    }
    var mn = n, mx = 0
//    print(f)
    for i in 0...A {
        for j in 0...B {
            mn = min(mn, f[i][j])
            mx = max(mx, f[i][j])
        }
    }
    return [mn, mx]
}

//print(solve())
//printBool(solve())
//printArray(solve())
printInline(solve())

