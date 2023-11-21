# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        #use floyd's algorithm
        self.max_sum = float('-inf')
        def dfs(node):
            if not node:
                return 0
            left = dfs(node.left)
            right = dfs(node.right)
            self.max_sum = max(self.max_sum, left + right + node.val)
            #return the max sum of the path that can be extended to the parent node
            return max(0, max(left, right) + node.val)
        dfs(root)
        return self.max_sum