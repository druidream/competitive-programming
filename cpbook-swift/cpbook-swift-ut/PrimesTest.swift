//
//  PrimesTest.swift
//  cpbook-swift-ut
//
//  Created by Jun Gu on 2023/4/11.
//

import XCTest

final class PrimesTest: XCTestCase {

    func testExtEuclid() throws {
        var x = 0, y = 0
        let v = extEuclid(25, 18, &x, &y)
        XCTAssertEqual(v, 1)
        XCTAssertEqual(x, -5)
        XCTAssertEqual(y, 7)
    }
}
