//
//  TreeNode.swift
//  LeetCode
//
//  Created by Jun Gu on 2021/3/19.
//

import Foundation

public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init() { self.val = 0; self.left = nil; self.right = nil; }
    public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
    public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
        self.val = val
        self.left = left
        self.right = right
    }
}

extension TreeNode {
    convenience init?(_ nums: [Int]) {
        if nums.isEmpty {
            self.init()
            return
        }
        
        var levelNumCount = 1
        var sumNumCount = 0
        self.init(nums[0])
        var node: TreeNode? = self
        for i in 0..<nums.count {
            node = self
            if sumNumCount + levelNumCount <= i + 1 {
                sumNumCount += levelNumCount
                levelNumCount *= 2
            }

            var levelPos = i - sumNumCount
            while levelPos > 1 {
                if levelPos % 2 == 0 {
                    node = node?.left
                } else {
                    node = node?.right
                }
                levelPos /= 2
            }

            if levelPos == 0 {
                node?.left = TreeNode(nums[i])
            } else {
                node?.right = TreeNode(nums[i])
            }
        }
    }
}
