/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, 0, cur, res);
        return res;
    }

    void dfs(vector<int>& nums, int index, vector<int>& cur, vector<vector<int>>& res) {
        if (index == nums.size()) {
            res.push_back(cur);
            return;
        }
        dfs(nums, index + 1, cur, res);
        cur.push_back(nums[index]);
        dfs(nums, index + 1, cur, res);
        cur.pop_back();
    }
};
// @lc code=end

