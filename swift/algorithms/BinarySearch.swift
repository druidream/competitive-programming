//
//  main.swift
//  BinarySearch
//
//  Created by Jun Gu on 2022/8/20.
//

import Foundation

print("Hello, World!")


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

let nums = [5,7,7,8,8,10]
print(lower_bound(nums, 4))
print(lower_bound(nums, 8))
print(lower_bound(nums, 9))
print(lower_bound(nums, 11))

print(upper_bound(nums, 4))
print(upper_bound(nums, 8))
print(upper_bound(nums, 9))
print(upper_bound(nums, 11))

var a = [Int]()
a.partition { $0 == 1 }
