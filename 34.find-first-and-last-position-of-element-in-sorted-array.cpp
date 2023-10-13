/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int mid, left, right, hit=-1;
        mid=left=0, right=nums.size()-1,hit=-1;
        while(left<=right){
            mid = (left+right)/2;
            if(nums[mid] == target){
                hit = mid;
                break;
            }
            else if(nums[mid] > target){
                right = mid-1;
            }
            else{
                left = mid+1; 
            }
        }
        if(hit == -1) return {-1,-1};
        left = 0, right = hit-1;
        while(left<=right){
            mid = (left+right)/2;
            if(nums[mid] == target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        int left_bound = left;
        left = hit+1, right = nums.size()-1;
        while(left<=right){
            mid = (left+right)/2;
            if(nums[mid] == target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        int right_bound = right;
        return {left_bound, right_bound};
    }
};
// @lc code=end
//[5,7,7,8,8,10]
//8
int main(){
    int a[] = {5,7,7,8,8,10};
    vector<int> nums(a,a+6);
    Solution s;
    vector<int> res = s.searchRange(nums,8);   
}