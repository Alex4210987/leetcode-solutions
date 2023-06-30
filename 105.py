# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Given two integer arrays preorder and inorder where preorder 
# is the preorder traversal of a binary tree and inorder 
# is the inorder traversal of the same tree, construct 
# and return the binary tree.
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if len(preorder) == 0:
            return None
        root = TreeNode(preorder[0])
        if len(preorder) == 1:
            return root
        rootIndex = inorder.index(preorder[0])
        root.left = self.buildTree(preorder[1:rootIndex+1], inorder[:rootIndex])
        root.right = self.buildTree(preorder[rootIndex+1:], inorder[rootIndex+1:])
        return root