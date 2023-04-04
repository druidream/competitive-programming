//
//  Trie.swift
//  1268. Search Suggestions System
//
//  Created by Jun Gu on 2021/6/1.
//

import Foundation

class TrieNode {
    var children = [Character: TrieNode]()
    var isEnd = false
}

class Trie {
    private var root = TrieNode()

    /** Initialize your data structure here. */
    init() {

    }

    /** Inserts a word into the trie. */
    func insert(_ word: String) {
        var node = root
        for char in word {
            if let next = node.children[char] {
                node = next
            } else {
                let next = TrieNode()
                node.children[char] = next
                node = next
            }
        }
        node.isEnd = true
    }

    /** Returns if the word is in the trie. */
    func search(_ word: String) -> Bool {
        var node = root
        for char in word {
            if let next = node.children[char] {
                node = next
            } else {
                return false
            }
        }
        return node.isEnd
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    func startsWith(_ prefix: String) -> Bool {
        var node = root
        for char in prefix {
            if let next = node.children[char] {
                node = next
            } else {
                return false
            }
        }
        return true
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * let obj = Trie()
 * obj.insert(word)
 * let ret_2: Bool = obj.search(word)
 * let ret_3: Bool = obj.startsWith(prefix)
 */
