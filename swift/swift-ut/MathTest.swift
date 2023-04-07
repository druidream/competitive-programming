//
//  MathTest.swift
//  swift-ut
//
//  Created by Jun Gu on 2023/4/6.
//

import XCTest

final class MathTest: XCTestCase {

    func testGcd() throws {
        XCTAssertEqual(gcd(6, 2), 2)
        XCTAssertEqual(gcd(3, 2), 1)
        XCTAssertEqual(gcd(6, 0), 6) // gcd with 0
        XCTAssertEqual(gcd(6, -2), 2) // gcd with neg
    }

    func testLcm() throws {
        XCTAssertEqual(lcm(4, 6), 12)
        XCTAssertEqual(lcm(3, 8), 24)
    }

    func testFactorFreq() throws {
        print(factorFreq(30))
        print(factorFreq(280))
        print(factorFreq(1024))
        print(factorFreq(Int(1e9+7)))
    }
}
