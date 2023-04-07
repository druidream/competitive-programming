//
//  main.swift
//  PriorityQueue
//
//  Created by Jun Gu on 2022/9/1.
//

import Foundation

//https://www.raywenderlich.com/books/data-structures-algorithms-in-swift/v4.0/chapters/22-heaps
struct PriorityQueue<T> {
    private var items = [T]()
    private var sort: (T, T) -> Bool
    init(sort: @escaping (T, T) -> Bool, items: [T] = []) {
        self.sort = sort
        for item in items {
            insert(item)
        }
    }

    var isEmpty: Bool {
        items.isEmpty
    }

    var count: Int {
        items.count
    }

    func peek() -> T? {
        items.first
    }

    mutating func remove() -> T? {
        if isEmpty { return nil }
        items.swapAt(0, count - 1)
        defer {
            sink(from: 0)
        }
        return items.removeLast()
    }

    mutating func insert(_ item: T) {
        items.append(item)
        swim(from: count - 1)
    }

    //
    private func leftChildIndex(ofParentAt index: Int) -> Int {
        2 * index + 1
    }

    private func rightChildIndex(ofParentAt index: Int) -> Int {
        2 * index + 2
    }

    private func parentIndex(ofChildAt index: Int) -> Int {
        (index - 1) / 2
    }

    private mutating func sink(from index: Int) {
        var parent = index
        while true {
            let left = leftChildIndex(ofParentAt: parent)
            let right = rightChildIndex(ofParentAt: parent)
            var candidate = parent
            if left < count && sort(items[left], items[candidate]) {
                candidate = left
            }
            if right < count && sort(items[right], items[candidate]) {
                candidate = right
            }
            if candidate == parent {
                return
            }
            items.swapAt(parent, candidate)
            parent = candidate
        }
    }

    private mutating func swim(from index: Int) {
        var child = index
        var parent = parentIndex(ofChildAt: child)
        while child > 0 && sort(items[child], items[parent]) {
            items.swapAt(child, parent)
            child = parent
            parent = parentIndex(ofChildAt: child)
        }
    }
}
