//
//  main.swift
//  TestCaseGenerator
//
//  Created by Gu Jun on 2023/5/3.
//  Copyright © 2023 Gu Jun. All rights reserved.
//

import Foundation

func distinctNumbers(_ n: Int, _ lo: Int, _ hi: Int) -> [Int] {
    var set = Set<Int>()
    while set.count < n {
        let rand = Int.random(in: lo...hi)
        set.insert(rand)
    }
    return Array(set)
}

func cf1608c() {
    print(1)
    let n = 10
    print(n)
    let a = distinctNumbers(n, 1, Int(1e9))
    let b = distinctNumbers(n, 1, Int(1e9))
    print(a.map({ String($0) }).joined(separator: " "))
    print(b.map({ String($0) }).joined(separator: " "))
}

cf1608c()
