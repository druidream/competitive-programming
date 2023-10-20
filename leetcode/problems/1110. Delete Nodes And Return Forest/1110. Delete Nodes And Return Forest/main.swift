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
    func delNodes(_ root: TreeNode?, _ to_delete: [Int]) -> [TreeNode?] {
        let set = Set(to_delete)
        var res = [TreeNode?]()
        func dfs(_ node: TreeNode?, _ isRoot: Bool) {
            if node == nil { return }
            if set.contains(node!.val) {
                dfs(node?.left, true)
                dfs(node?.right, true)
            } else {
                if isRoot {
                    res.append(node)
                }
                if let left = node?.left?.val {
                    if set.contains(left) {
                        dfs(node?.left, true)
                        node?.left = nil
                    } else {
                        dfs(node?.left, false)
                    }
                }
                if let right = node?.right?.val {
                    if set.contains(right) {
                        dfs(node?.right, true)
                        node?.right = nil
                    } else {
                        dfs(node?.right, false)
                    }
                }
            }
        }
        dfs(root, true)
        return res
    }
}

print(Solution().delNodes(TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3, TreeNode(6), TreeNode(7))), [3, 5]))
