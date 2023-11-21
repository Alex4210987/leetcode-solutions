#include<vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        else if (root->left == nullptr && root->right == nullptr) return {root->val};
        else {
            vector<int> left = rightSideView(root->left);
            vector<int> right = rightSideView(root->right);
            vector<int> res;
            if (left.size() > right.size()) {
                res.push_back(root->val);
                for (int i = 0; i < left.size(); i++) {
                    res.push_back(left[i]);
                }
            } else {
                res.push_back(root->val);
                for (int i = 0; i < right.size(); i++) {
                    res.push_back(right[i]);
                }
            }
            return res;
        }
    }
};