//
//  SegmentTreeTest.swift
//  cpbook-swift-ut
//
//  Created by Jun Gu on 2023/2/20.
//

import XCTest

final class SegmentTreeTest: XCTestCase {

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
        let A = [18, 17, 13, 19, 15, 11, 20, 99]    // make n a power of 2
        let st = SegmentTree(A)
        XCTAssertEqual(st.RMQ(1, 3), 13)            // 13
        XCTAssertEqual(st.RMQ(4, 7), 11)            // 11
        XCTAssertEqual(st.RMQ(3, 4), 15)            // 15

        st.update(5, 5, 77)                         // update A[5] to 77
        XCTAssertEqual(st.RMQ(1, 3), 13)            // remains 13
        XCTAssertEqual(st.RMQ(4, 7), 15)            // now 15
        XCTAssertEqual(st.RMQ(3, 4), 15)            // remains 15

        st.update(0, 3, 30)                         // update A[0..3] to 30
        XCTAssertEqual(st.RMQ(1, 3), 30)            // now 30
        XCTAssertEqual(st.RMQ(4, 7), 15)            // remains 15
        XCTAssertEqual(st.RMQ(3, 4), 15)            // remains 15

        st.update(3, 3, 7)                         // update A[3] to 7
        XCTAssertEqual(st.RMQ(1, 3), 7)            // now 7
        XCTAssertEqual(st.RMQ(4, 7), 15)            // remains 15
        XCTAssertEqual(st.RMQ(3, 4), 7)            // now 7
    }

    func testPerformanceExample() throws {
        // This is an example of a performance test case.
        self.measure {
            // Put the code you want to measure the time of here.
        }
    }

}
