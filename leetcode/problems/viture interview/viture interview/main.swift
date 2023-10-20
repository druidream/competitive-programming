//
//  main.swift
//  viture interview
//
//  Created by Gu Jun on 2023/7/25.
//  Copyright © 2023 Gu Jun. All rights reserved.
//

import Foundation

func add(_ s: String, _ t: String) -> String {
    let s = Array(s.reversed()), t = Array(t.reversed())
    let n = s.count, m = t.count
    var carry = 0
    var i = 0, j = 0
    var res = ""
    while i < n || j < m || carry > 0 {
        var v = carry
        if i < n {
            v += Int(s[i].asciiValue! - 48)
            i += 1
        }
        if j < m {
            v += Int(t[j].asciiValue! - 48)
            j += 1
        }
        res += String(v % 10)
        carry = v / 10
    }
    return String(res.reversed())
}

let a = [1,2,3,4]
let b = 2
//print(a ~= b)
let s: String = "bab"
let t = "a"
s.range(of: t)
s.contains(t)
//if s.replacingOccurrences(of: t, with: t) == s { print(String(s)) } else {print("x")}

func g(_ s: String, _ t: String) -> Bool {
    if s.count < t.count { return false }
    let s = Array(s), t = Array(t)
    let n = s.count, m = t.count
    for i in 0..<n {
        let j = i + m
        if j > n { break }
        var ok = true
        for k in 0..<m {
            if s[i + k] != t[k] { ok = false; break }
        }
        if ok { return true }
    }
    return false
}
func f(_ s: String, _ t: String) -> String {
    if g(s, t) { return s }
    if g(t, s) { return t }
    let s = Array(s), t = Array(t)
    let n = s.count, m = t.count
    let len = min(s.count, t.count)
    var mx = 0
    for d in 1...len {
        let tt = t[0..<d]
        let ss = s[n - d...n - 1]
        if ss == tt {
            mx = max(mx, d)
        }
    }
    let res = s + t[mx..<m]
    print(String(s), String(t), String(res), mx)
    return String(res)
}
//print(f("a", "cac"))
//print(g("cac", "a"))
