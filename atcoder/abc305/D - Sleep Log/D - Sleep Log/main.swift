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
    let n = read1()
    let a = readInts()
    var pre = Array(repeating: 0, count: n + 1)
    for i in 0..<n {
        if i > 0 && i % 2 == 0 {
            let v = a[i] - a[i - 1]
            pre[i + 1] = pre[i] + v
        } else {
            pre[i + 1] = pre[i]
        }
    }
    let q = read1()
    var res = [Int]()
    for _ in 0..<q {
        let (l, r) = read2()
        var lo = 0, hi = n - 1
        while lo <= hi {
            let mid = (lo + hi) / 2
            if a[mid] >= l {
                hi = mid - 1
            } else {
                lo = mid + 1
            }
        }
        var left = pre[lo + 1]
        if lo > 0 && lo % 2 == 0 {
            left -= a[lo] - l
        }
        lo = 0; hi = n - 1
        while lo <= hi {
            let mid = (lo + hi) / 2
            if a[mid] >= r {
                hi = mid - 1
            } else {
                lo = mid + 1
            }
        }
        var right = pre[lo + 1]
        if lo > 0 && lo % 2 == 0 {
            right -= a[lo] - r
        }
//        print(pre, right, left)
        res.append(right - left)
    }
    return res
}

//print(solve())
//printBool(solve())
printArray(solve())
//printInline(solve())

