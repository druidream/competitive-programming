//
//  FenwickTreeTest.swift
//  cpbook-swift-ut
//
//  Created by Jun Gu on 2023/2/20.
//

import XCTest

final class FenwickTreeTest: XCTestCase {

    override func setUpWithError() throws {
        // Put setup code here. This method is called before the invocation of each test method in the class.
    }

    override func tearDownWithError() throws {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
    }

    func testExample() throws {
        // This is an example of a functional test case.
        // Use XCTAssert and related functions to verify your tests produce the correct results.
        // Any test you write for XCTest can be annotated as throws and async.
        // Mark your test throws to produce an unexpected failure when your test encounters an uncaught error.
        // Mark your test async to allow awaiting for asynchronous code to complete. Check the results with assertions afterwards.
        let f = [0,0,1,0,1,2,3,2,1,1,0]     // index 0 is always 0
        let ft = FenwickTree(f)
        XCTAssertEqual(ft.rsq(1, 6), 7)     // 7 => ft[6]+ft[4] = 5+2 = 7
        XCTAssertEqual(ft.select(7), 6)     // index 6, rsq(1, 6) == 7, which is >= 7

        ft.update(5, 1)
        XCTAssertEqual(ft.rsq(1, 10), 12)   // now 12

        let rupq = RUPQ(10)
        let rurq = RURQ(10)
        rupq.range_update(2, 9, 7)          // indices in [2, 3, .., 9] updated by +7
        rurq.range_update(2, 9, 7)          // same as rupq above
        rupq.range_update(6, 7, 3)          // indices 6&7 are further updated by +3 (10)
        rurq.range_update(6, 7, 3)          // same as rupq above
        // idx = 0 (unused) | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |10
        // val = -          | 0 | 7 | 7 | 7 | 7 |10 |10 | 7 | 7 | 0
        for i in 1...10 {
            print(rupq.point_query(i))
        }
        XCTAssertEqual(rurq.rsq(1, 10), 62)
        XCTAssertEqual(rurq.rsq(6, 7), 20)
    }
}
