# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        self.pre = None
        return self.helper(root)

    def helper(self, root):
        if root is None:
            return True

        if not self.helper(root.left):
            return False

        if self.pre and self.pre.val >= root.val:
            return False
        self.pre = root

        return self.helper(root.right)
