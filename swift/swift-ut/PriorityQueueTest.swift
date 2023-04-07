//
//  PriorityQueueTest.swift
//  swift-ut
//
//  Created by Jun Gu on 2023/4/6.
//

import XCTest

final class PriorityQueueTest: XCTestCase {

    func testPriorityQueue() throws {
        let nums = [1,12,3,4,1,6,8,7]
        var heap = PriorityQueue(sort: >, items: nums)
        var res = [Int]()
        while !heap.isEmpty {
            res.append(heap.remove()!)
        }
        XCTAssertEqual(res, nums.sorted(by: >))
    }
}
