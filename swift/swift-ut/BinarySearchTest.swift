//
//  BinarySearchTest.swift
//  swift-ut
//
//  Created by Jun Gu on 2023/4/6.
//

import XCTest

final class BinarySearchTest: XCTestCase {

    func testBinarySearch() throws {
        let nums = [5,7,7,8,8,10] // sorted non-decreasing
        XCTAssertEqual(lower_bound(nums, 4), 0) // index
        XCTAssertEqual(lower_bound(nums, 8), 3)
        XCTAssertEqual(lower_bound(nums, 9), 5)
        XCTAssertEqual(lower_bound(nums, 11), 6) // can go out of bound when x is too big

        XCTAssertEqual(upper_bound(nums, 4), -1) // can go out of bound when x is too small
        XCTAssertEqual(upper_bound(nums, 8), 4)
        XCTAssertEqual(upper_bound(nums, 9), 4)
        XCTAssertEqual(upper_bound(nums, 11), 5)
    }

    func testExample() throws {
        var a = [Int]()
        a.partition { $0 == 1 }
    }
}
