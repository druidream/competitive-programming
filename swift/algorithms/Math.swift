//
//  main.swift
//  Math
//
//  Created by Jun Gu on 2022/11/20.
//

import Foundation

// a, b should be non negative integers
func gcd(_ a: Int, _ b: Int) -> Int {
    let a = abs(a), b = abs(b)
    return b > 0 ? gcd(b, a % b) : a
}

func lcm(_ a: Int, _ b: Int) -> Int {
    return a / gcd(a, b) * b
}




func qpow(_ x: Double, _ n: Int) -> Double {
    if n == 0 { return 1.0 }
    if n == 1 { return x }
    if n < 0 { return 1 / qpow(x, -n)}
    let v = qpow(x, n / 2)
    var ans = v * v
    if n % 2 == 1 {
        ans *= x
    }
    return ans
}

let mod = Int(1e9 + 7)
func qpow(_ x: Int, _ n: Int) -> Int {
    if n == 0 { return 1 }
    if n == 1 { return x }
    if n < 0 { return 1 / qpow(x, -n)}
    let v = qpow(x, n / 2)
    var ans = (v * v) % mod
    if n % 2 == 1 {
        ans = (ans * x) % mod
    }
    return (ans + mod) % mod
}


/* TODO:
 // CLRS P.1185
 // P(n, k) = n! / (n - k)!
func P(_ n: Int, _ k: Int) -> Int {
}

// C(n,m)=C(n-1,m-1)+C(n-1,m)
 // C(n, k) = n! / (k! * (n - k)!)
func C(_ m: Int, _ n: Int) -> Int {

}

 https://codeforces.com/contest/1436/submission/96620271
 func A(n, m int) int64 {
     if m > n { return 0 }
     x := int64(1)
     for i := 0; i < m; i++ {
         x = x * int64(n-i) % mod
     }
     return x
 }
 */

// MARK: - freq map of factors of num
// abc280_d
func factorFreq(_ k: Int) -> [Int: Int] {
    var mp = [Int: Int]() // facter: count
    var x = k
    for f in 2...k {
        if f * f > k { break }
        while x % f == 0 {
            mp[f, default: 0] += 1
            x /= f
        }
    }
    if x != 1 {
        mp[x] = 1
    }
    return mp
}


// MARK: - set of distint factors of num
func factorSet(_ num: Int) -> Set<Int> {
    var set = Set<Int>()
    var x = num
    for f in stride(from: 2, through: num, by: 1) {
        if f * f > num { break }
        while x % f == 0 {
            set.insert(f)
            x /= f
        }
    }
    if x != 1 {
        set.insert(x)
    }
    return set
}

// MARK: - if num is a prime number (1 is not a prime number)
func isPrime(_ num: Int) -> Bool {
    if num == 1 { return false }
    var x = num
    for f in 2..<num {
        if f * f > num { break }
        if x % f == 0 { return false }
    }
    return true
}

