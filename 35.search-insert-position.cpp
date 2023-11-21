/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1, mid;
        if(target<=nums[0]) return left;
        if(target>nums[right]) return right+1;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]>=target&&nums[mid-1]<target){
                return mid;
            }
            else if(nums[mid]<target) left=mid+1;
            else if(nums[mid-1]>=target) right=mid-1;
        }
        return left;
    }
};
// @lc code=end

