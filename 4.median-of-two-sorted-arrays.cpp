/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            nums.push_back(nums1[i] < nums2[j] ? nums1[i++] : nums2[j++]);
        }
        while (i < nums1.size()) {
            nums.push_back(nums1[i++]);
        }
        while (j < nums2.size()) {
            nums.push_back(nums2[j++]);
        }
        int mid = nums.size() / 2;
        return nums.size() % 2 == 0 ? (nums[mid] + nums[mid - 1]) / 2.0 : nums[mid];
    }
};
// @lc code=end