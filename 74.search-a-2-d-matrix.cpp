/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); if (m == 0) return false;
        int n = matrix[0].size(); if (n == 0) return false;

        int i = 0, j = n - 1;
        while (i < m && j >= 0) {// 从右上角开始
            if (matrix[i][j] == target) return true;// 如果当前元素等于目标值，返回true
            else if (matrix[i][j] < target) ++i;// 如果当前元素小于目标值，行数加1
            else --j;// 如果当前元素大于目标值，列数减1
        }

        return false;
    }
};
// @lc code=end

