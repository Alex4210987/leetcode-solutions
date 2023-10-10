/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        int i, left, right, sum;
        i=1;
        sort(nums.begin(),nums.end());
        // first we determin a num using loop. thus we know the average of the other 2. use 2 pointers 2
        // find out if the other 2 exists
        // remember 2 delete the triplet from vector 
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) break; // 如果当前数大于 0，则直接退出循环
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 如果当前数与上一个数相同，则直接跳过
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) { // 如果三个数的和等于 0，则将它们加入结果数组中
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++; // 跳过重复的数字
                    while (left < right && nums[right] == nums[right - 1]) right--; // 跳过重复的数字
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return res;
    }
};
// @lc code=end