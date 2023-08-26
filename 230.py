# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def inorder(self, root:TreeNode):# left then right
        if root is None or self.k==0:
            return
        self.inorder(root.left)
        self.k-=1
        if self.k==0:
            self.result=root.val
            return
        self.inorder(root.right)
        return
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        self.k=k
        self.result=0
        self.inorder(root)
        return self.result
