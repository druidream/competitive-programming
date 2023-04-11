//
//  primes.swift
//  cpbook-swift
//
//  Created by Jun Gu on 2023/4/10.
//

import Foundation

var sieveSize = 0
var bs = Array(repeating: 1, count: 10000010)
var p = [Int]()

// Sieve of Eratosthenes
func sieve(_ upperbound: Int) {
    sieveSize = upperbound + 1
    bs[0] = 0; bs[1] = 0
    for i in stride(from: 2, through: sieveSize, by: 1) where bs[i] > 0 {
        // cross out multiples of i starting from i*i
        for j in stride(from: i * i, through: sieveSize, by: i) { bs[j] = 0 }
        p.append(i)
    }
}

func isPrime(_ n: Int) -> Bool {
    if n < sieveSize { return bs[n] > 0 }           // O(1) for small primes
    for i in 0..<p.count where p[i] * p[i] <= n {
        if n % p[i] == 0 {
            return false
        }
    }
    return true                                     // slow if N = large prime
} // note: only guaranteed to work for N <= (last prime in vll p)^2

func numPF(_ n: Int) -> Int {
    var ans = 0, n = n
    for i in 0..<p.count where p[i] * p[i] <= n {
        while n % p[i] == 0 { n /= p[i]; ans += 1 }
    }
    return ans + (n != 1 ? 1 : 0)
}

func numDiffPF(_ n: Int) -> Int {
    var ans = 0, n = n
    for i in 0..<p.count where p[i] * p[i] <= n {
        if n % p[i] == 0 { ans += 1 }
        while n % p[i] == 0 { n /= p[i] }
    }
    return ans + (n != 1 ? 1 : 0)
}

func sumPF(_ n: Int) -> Int {
    var ans = 0, n = n
    for i in 0..<p.count where p[i] * p[i] <= n {
        while n % p[i] == 0 { n /= p[i]; ans += p[i] }
    }
    return ans + (n != 1 ? n : 0)
}

func numDiv(_ n: Int) -> Int {
    var ans = 1, n = n
    for i in 0..<p.count where p[i] * p[i] <= n {
        var power = 0
        while n % p[i] == 0 { n /= p[i]; power += 1 }
        ans *= power + 1
    }
    return n != 1 ? ans * 2 : ans
}

func sumDiv(_ n: Int) -> Int {
    var ans = 1, n = n
    for i in 0..<p.count where p[i] * p[i] <= n {
        var multiplier = p[i], total = 1
        while n % p[i] == 0 {
            n /= p[i]
            total += multiplier
            multiplier *= p[i]
        }
        ans *= total
    }
    if n != 1 { ans *= n + 1 }
    return ans
}

func EulerPhi(_ n: Int) -> Int {
    var ans = n, n = n
    for i in 0..<p.count where p[i] * p[i] <= n {
        if n % p[i] == 0 { ans -= ans / p[i] }
        while n % p[i] == 0 { n /= p[i] }
    }
    if n != 1 { ans -= ans / n }
    return ans
}
