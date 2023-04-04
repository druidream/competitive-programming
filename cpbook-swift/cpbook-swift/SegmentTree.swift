//
//  SegmentTree.swift
//  cpbook-swift
//
//  Created by Jun Gu on 2023/2/20.
//

import Foundation

class SegmentTree {
    let n: Int
    var A = [Int](), st = [Int](), lazyTag = [Int]()

    init(_ sz: Int) {
        n = sz
        st = Array(repeating: 0, count: 4 * n)
        lazyTag = Array(repeating: -1, count: 4 * n)
    }

    convenience init(_ initialA: [Int]) {
        self.init(initialA.count)
        A = initialA
        build(1, 0, n - 1)
    }

    private func l(_ p: Int) -> Int { return p << 1 }       // go to left child
    private func r(_ p: Int) -> Int { return (p << 1) + 1 } // go to right child

    private func conquer(_ a: Int, _ b: Int) -> Int {
        if a == -1 { return b }                     // corner case
        if b == -1 { return a }
        return min(a, b)                            // RMQ
    }

    private func build(_ p: Int, _ L: Int, _ R: Int) {
        if L == R {
            st[p] = A[L]
        } else {
            let m = (L + R) / 2
            build(l(p), L, m)
            build(r(p), m + 1, R)
            st[p] = conquer(st[l(p)], st[r(p)])
        }
    }

    private func propagate(_ p: Int, _ L: Int, _ R: Int) {
        if lazyTag[p] != -1 {                       // has a lazy flag
            st[p] = lazyTag[p]                      // [L..R] has same value
            if L != R {                             // not a leaf
                lazyTag[l(p)] = lazyTag[p]          // propagate downwards
                lazyTag[r(p)] = lazyTag[p]
            } else {                                // L == R, a single index
                A[L] = lazyTag[p]                   // time to update this
            }
            lazyTag[p] = -1                         // erase lazy flag
        }
    }

    // O(log n)
    private func RMQ(_ p: Int, _ L: Int, _ R: Int, _ i: Int, _ j: Int) -> Int {
        propagate(p, L, R)                          // lazy propagation
        if i > j { return -1 }                      // infeasible
        if L >= i && R <= j { return st[p] }        // found the segment
        let m = (L + R) / 2
        return conquer(RMQ(l(p), L, m, i, min(m, j)),
                       RMQ(r(p), m + 1, R, max(i, m + 1), j))
    }

    // O(log n)
    private func update(_ p: Int, _ L: Int, _ R: Int, _ i: Int, _ j: Int, _ val: Int) {
        propagate(p, L, R)
        if i > j { return }
        if L >= i && R <= j {
            lazyTag[p] = val
            propagate(p, L, R)
        } else {
            let m = (L + R) / 2
            update(l(p), L, m, i, min(m, j), val)
            update(r(p), m + 1, R, max(i, m + 1), j, val)
            let lsubtree = lazyTag[l(p)] != -1 ? lazyTag[l(p)] : st[l(p)]
            let rsubtree = lazyTag[r(p)] != -1 ? lazyTag[r(p)] : st[r(p)]
            st[p] = lsubtree <= rsubtree ? st[l(p)] : st[r(p)]
        }
    }

    func update(_ i: Int, _ j: Int, _ val: Int) {
        update(1, 0, n - 1, i, j, val)
    }

    func RMQ(_ i: Int, _ j: Int) -> Int {
        RMQ(1, 0, n - 1, i, j)
    }
}
