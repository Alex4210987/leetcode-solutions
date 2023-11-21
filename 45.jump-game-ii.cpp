/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int res = 0;
        int curMax = 0, nextMax = 0;
        for(int i = 0; i < n - 1; i++) {
            nextMax = max(nextMax, i + nums[i]);
            if(i == curMax) {
                res++;
                curMax = nextMax;
            }
        }
        return res;
    }
};
// @lc code=end

