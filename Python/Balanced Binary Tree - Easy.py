# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:

    def countLeft(self, root: TreeNode) -> int:
        count = 0
        if root and root.left != None:
            count += 1
            return count + self.countLeft(root.left)
        else:
            return count

    def countRight(self, root: TreeNode) -> int:
        count = 0
        if root and root.right != None:
            count += 1
            return count + self.countLeft(root.right)
        else:
            return count

    def isBalanced(self, root: TreeNode) -> bool:
        if self.countLeft(root) - self.countRight(root) <= 1:
            return True
        else:
            False


tree1 = TreeNode(0)
assert Solution().countLeft(tree1) == 0