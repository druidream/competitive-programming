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


func solve() -> Int {
    let n = read1()
    let a = readInts()
    let s = Array(readLine()!)
    var f = Array(repeating: Array(repeating: 0, count: 3), count: n)
    var g = Array(repeating: Array(repeating: 0, count: 3), count: n)
    if s[0] == "M" {
        f[0][a[0]] = 1
    }
    for i in 1..<n {
        for j in 0..<3 {
            f[i][j] = f[i - 1][j]
        }
        if s[i] == "M" {
            f[i][a[i]] += 1
        }
    }

    if s[n - 1] == "X" {
        g[n - 1][a[n - 1]] = 1
    }
    for i in (0..<n - 1).reversed() {
        for j in 0..<3 {
            g[i][j] = g[i + 1][j]
        }
        if s[i] == "X" {
            g[i][a[i]] += 1
        }
    }
    var ans = 0
    for i in 0..<n {
        var v = 0
        if s[i] == "E" {
            if a[i] == 0 {
                let cnt1 = (f[i][0] + f[i][2]) * (g[i][0] + g[i][2])
                let cnt2 = f[i][1] * (g[i][0] + g[i][1]) + g[i][1] * (f[i][0] + f[i][1]) - f[i][1] * g[i][1]
                let cnt3 = f[i][1] * g[i][2] + f[i][2] * g[i][1]
                v = cnt1 + cnt2 * 2 + cnt3 * 3
//                print("AAA i: \(i), a[i]: \(a[i]), v: \(v)")
            } else if a[i] == 1 {
                let cnt2 = f[i][0] * (g[i][0] + g[i][1]) + (f[i][0] + f[i][1]) * g[i][0] - f[i][0] * g[i][0]
                let cnt3 = f[i][0] * g[i][2] + f[i][2] * g[i][0]
                v = cnt2 * 2 + cnt3 * 3
//                print("BBB i: \(i), a[i]: \(a[i]), v: \(v)", cnt2, cnt3)
            } else if a[i] == 2 {
                let cnt1 = f[i][0] * (g[i][0] + g[i][2]) + (f[i][0] + f[i][2]) * g[i][0] - f[i][0] * g[i][0]
                let cnt3 = f[i][0] * g[i][1] + f[i][1] * g[i][0]
                v = cnt1 + cnt3 * 3
//                print("CCC i: \(i), a[i]: \(a[i]), v: \(v)")
            }
        }
        ans += v
//        print(i, ans)
    }
//    print(f)
//    print(g)
    return ans
}

print(solve())
//printBool(solve())
//printArray(solve())
//printInline(solve())

