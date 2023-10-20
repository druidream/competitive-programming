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

let s = Array(readLine()!)
let t = Array(readLine()!)
let n = s.count

func solve() -> Bool {
    let cs = Set(Array("atcoder").map({ Int($0.asciiValue! - 97) }))
    var f = Array(repeating: 0, count: 26)
    var cnts = 0, cntt = 0
    for i in 0..<n {
        if s[i] == "@" {
            cnts += 1
        } else {
            let idx = Int(s[i].asciiValue! - 97)
            f[idx] += 1
        }
        if t[i] == "@" {
            cntt += 1
        } else {
            let idx = Int(t[i].asciiValue! - 97)
            f[idx] -= 1
        }
    }
    for i in 0..<26 {
        if f[i] != 0 && !cs.contains(i) { return false }
        if f[i] > 0 {
            cntt -= f[i]
        } else if f[i] < 0 {
            cnts += f[i]
        }
    }
    return cnts == cntt && cnts >= 0
}

//print(solve())
printBool(solve())
//printArray(solve())
//printInline(solve())

