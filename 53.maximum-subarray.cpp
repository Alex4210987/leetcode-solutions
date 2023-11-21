/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, sum = 0;
        for (int num : nums) {
            sum = max(sum + num, num);
            res = max(res, sum);
        }
        return res;
    }
};
// @lc code=end

