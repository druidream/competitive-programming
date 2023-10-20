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

class Solution {
    func lcaDeepestLeaves(_ root: TreeNode?) -> TreeNode? {
        var pa = Array(repeating: 0, count: 1001)
        var mp = [Int: TreeNode]()
        var q = [(TreeNode, Int)]()
        q.append((root!, -1))
        while !q.isEmpty {
            var nq = [(TreeNode, Int)]()
            for _ in 0..<q.count {
                let (node, p) = q.removeFirst()
                mp[node.val] = node
                let v = node.val
                pa[v] = p
                if node.left != nil {
                    nq.append((node.left!, v))
                }
                if node.right != nil {
                    nq.append((node.right!, v))
                }
            }
            if nq.isEmpty {
                break
            } else {
                q = nq
            }
        }
        if q.count == 1 { return q[0].0 }
        var dep = 1000, ans = -1
        for i in 1..<q.count {
            let (node1, _) = q[i - 1]
            let (node2, _) = q[i]
            var u = node1.val, v = node2.val
            var d = 0
            while u != v {
                u = pa[u]
                v = pa[v]
                d += 1
            }
            if d < dep {
                dep = d
                ans = u
            }
        }
        return mp[ans]
    }
}

let tree = TreeNode(0, TreeNode(1, nil, TreeNode(2)), TreeNode(3))
print(Solution().lcaDeepestLeaves(tree))
