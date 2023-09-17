/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {

        int ans = 0;
        depth(root, ans);
        return ans;
    }

    int depth(TreeNode* root, int& ans) {
        if (!root) return 0;
        int left = depth(root->left, ans);
        int right = depth(root->right, ans);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }
};
// @lc code=end

