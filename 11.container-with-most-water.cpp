/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() -1;
        int maxArea = 0;
        while(left < right){
            maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
            if(height[left] < height[right]) left++;
            else right--;
        }
        return maxArea;
    }
};
// @lc code=end

