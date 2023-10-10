/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex; // 用于存储数字和它们的索引

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // 如果在哈希表中找到了与当前数字相加等于目标值的数字
            if (numToIndex.find(complement) != numToIndex.end()) {
                // 返回两个数字的索引
                return {numToIndex[complement], i};
            }
            
            // 否则将当前数字及其索引添加到哈希表中
            numToIndex[nums[i]] = i;
        }

        // 如果没有找到匹配的数字对，可以根据问题要求返回一个默认值
        return {};
    }
};

// @lc code=end

