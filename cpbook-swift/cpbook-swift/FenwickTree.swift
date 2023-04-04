//
//  FenwickTree.swift
//  cpbook-swift
//
//  Created by Jun Gu on 2023/2/20.
//

import Foundation

class FenwickTree {
    private var ft: [Int]

    func LSOne(_ S: Int) -> Int { S & -S }      // the key operation

    init(_ m: Int) {                            // create an empty FT
        ft = Array(repeating: 0, count: m + 1)
    }

    func build(_ f: [Int]) {
        let m = f.count - 1
        ft = Array(repeating: 0, count: m + 1)
        for i in 1...m {
            ft[i] += f[i]                       // add this value
            if i + LSOne(i) <= m {              // i has parent
                ft[i + LSOne(i)] += ft[i]       // add to that parent
            }
        }
    }

    convenience init(_ f: [Int]) {              // create FT based on f
        self.init(f.count)
        build(f)
    }

    convenience init(_ m: Int, _ s: [Int]) {    // create FT based on s
        self.init(m)
        var f = Array(repeating: 0, count: m + 1)
        for i in 0..<s.count {
            f[s[i]] += 1
        }
        build(f)
    }

    func rsq(_ j: Int) -> Int {
        var sum = 0, j = j
        while j > 0 {
            sum += ft[j]
            j -= LSOne(j)
        }
        return sum                              // returns RSQ(1, j)
    }

    func rsq(_ i: Int, _ j: Int) -> Int {
        return rsq(j) - rsq(i - 1)              // inc/exclusion
    }

    func update(_ i: Int, _ v: Int) {
        var i = i
        while i < ft.count {
            ft[i] += v
            i += LSOne(i)
        }
    }

    func select(_ k: Int) -> Int {
        var p = 1, k = k
        while p * 2 < ft.count {
            p *= 2
        }
        var i = 0
        while p > 0 {
            if k > ft[i + p] {
                k -= ft[i + p]
                i += p
            }
            p /= 2
        }
        return i + 1
    }
}

class RUPQ {                                    // RUPQ variant
    private var ft: FenwickTree

    init(_ m: Int) {
        ft = FenwickTree(m)                     // internally use PURQ FT
    }

    func range_update(_ ui: Int, _ uj: Int, _ v: Int) {
        ft.update(ui, v)                        // [ui, ui+1, .., m] +v
        ft.update(uj + 1, -v)                   // [uj+1, uj+2, .., m] -v
    }                                           // [ui, ui+1, .., uj] +v

    func point_query(_ i: Int) -> Int {
        return ft.rsq(i)                        // rsq(i) is sufficient
    }
}

class RURQ {                                    // RURQ variant
    private var rupq: RUPQ                      // needs two helper FTs, one RUPQ and
    private var purq: FenwickTree               // one PURQ

    init(_ m: Int) {
        rupq = RUPQ(m)
        purq = FenwickTree(m)
    }

    func range_update(_ ui: Int, _ uj: Int, _ v: Int) {
        rupq.range_update(ui, uj, v)            // [ui, ui+1, .., uj] +v
        purq.update(ui, v * (ui - 1))           // -(ui-1)*v before ui
        purq.update(uj + 1, -v * uj)            // +(uj-ui+1)*v after uj
    }

    func rsq(_ j: Int) -> Int {
        return rupq.point_query(j) * j -        // optimistic calculation
               purq.rsq(j)                      // cancelation factor
    }

    func rsq(_ i: Int, _ j: Int) -> Int {
        return rsq(j) - rsq(i - 1)
    }
}
