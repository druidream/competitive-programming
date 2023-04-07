//
//  main.swift
//  BinarySearch
//
//  Created by Jun Gu on 2022/8/20.
//

import Foundation

func lower_bound(_ nums: [Int], _ target: Int) -> Int {
    var lo = 0, hi = nums.count - 1
    while lo <= hi {
        let mid = (lo + hi) / 2
        if nums[mid] >= target {
            hi = mid - 1
        } else {
            lo = mid + 1
        }
    }
    return lo
}

func upper_bound(_ nums: [Int], _ target: Int) -> Int {
    var lo = 0, hi = nums.count - 1
    while lo <= hi {
        let mid = (lo + hi) / 2
        if nums[mid] > target {
            hi = mid - 1
        } else {
            lo = mid + 1
        }
    }
    return hi
}
