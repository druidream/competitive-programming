//
//  ListNode.swift
//  LeetCode
//
//  Created by Jun Gu on 2021/3/3.
//

public class ListNode: CustomStringConvertible {
    public var val: Int
    public var next: ListNode?
    public init() { self.val = 0; self.next = nil; }
    public init(_ val: Int) { self.val = val; self.next = nil; }
    public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
    
    public var description: String {
        var nums = [Int]()
        var node: ListNode? = self
        while node != nil {
            nums.append(node!.val)
            node = node?.next
        }
        
        return "[" + nums.map { String($0) }.joined(separator: ", ") + "]"
    }
}

extension ListNode {
    convenience init?(_ nums: [Int]) {
        if nums.isEmpty {
            self.init()
            return
        }
        self.init(nums[0])
        var prev: ListNode?
        for i in 0..<nums.count {
            if i == 0 {
                prev = self
            } else {
                let node = ListNode(nums[i])
                prev?.next = node
                prev = node
            }
        }
    }

    convenience init?(_ arrStr: String) {
        let nums = arrStr.dropFirst().dropLast().split(separator: ",").map { Int($0)! }
        self.init(nums)
    }
}
