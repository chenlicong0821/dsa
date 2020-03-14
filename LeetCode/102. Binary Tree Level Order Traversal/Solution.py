# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def levelOrder1(self, root: TreeNode) -> List[List[int]]:
        res = []
        if not root:
            return res

        queue = collections.deque()
        queue.append(root)
        # visited = set([root])

        while queue:
            level_size = len(queue)
            current_level = []
            for _ in range(level_size):
                node = queue.popleft()
                current_level.append(node.val)
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
            res.append(current_level)

        return res

    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root: return []
        self.result = []
        self._dfs(root, 0)
        return self.result

    def _dfs(self, node, level):
        if not node: return

        if len(self.result) < level + 1:
            self.result.append([])

        self.result[level].append(node.val)

        self._dfs(node.left, level + 1)
        self._dfs(node.right, level + 1)
