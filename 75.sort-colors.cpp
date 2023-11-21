/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> map(3,0);
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        nums.clear();
        for(int i=0;i<map[0];i++) nums.push_back(0);
        for(int i=0;i<map[1];i++) nums.push_back(1);
        for(int i=0;i<map[2];i++) nums.push_back(2);
    }
};
// @lc code=end