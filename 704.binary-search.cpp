/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            if(nums[(left+right)/2]==target){
                return (left+right)/2;
            }
            else if(nums[(left+right)/2]>target){
                right=(left+right)/2-1;
            }
            else{
                left=(left+right)/2+1;
            }
        }
        return -1;
    }
};
// @lc code=end