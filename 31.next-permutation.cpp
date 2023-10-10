/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-1;
        while(i>0&&nums[i]<=nums[i-1])i--;
        i--;
        if(i>=0){
            int j=i+1;
            while(j<nums.size()&&nums[j]>nums[i])j++;
            swap(nums[i],nums[--j]);
            sort(nums.begin()+i+1,nums.end());
        }
        else sort(nums.begin(),nums.end());
    }
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
};
// @lc code=end