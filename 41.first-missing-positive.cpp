/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //sort nunms
        sort(nums.begin(), nums.end());
        //find the first positive number
        int i = 0;
        while (i < nums.size() && nums[i] <= 0) {
            i++;
        }
        //if the first positive number is not 1, return 1
        if (i == nums.size() || nums[i] != 1) {
            return 1;
        }
        //if the first positive number is 1, find the first missing positive number
        int j = i;
        while (j < nums.size()-1 && (nums[j] == nums[j + 1] - 1 || nums[j] == nums[j + 1])) {
            j++;
        }
        return nums[j] + 1;
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector<int> nums = {1};
    cout << sol.firstMissingPositive(nums) << endl;
    return 0;
}