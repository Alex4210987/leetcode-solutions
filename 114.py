# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        def modify(root):
            if root is None:
                return None
            if root.left is None and root.right is None:
                return root
            left = modify(root.left)# left is the last node of the left subtree
            right = modify(root.right)
            if left is not None:
                left.right = root.right
                root.right = root.left
                root.left = None
            if right is not None:
                return right# if right is not None, then right is the last node of the right subtree
            return left# if right is None, then left is the last node of the right subtree
        modify(root)