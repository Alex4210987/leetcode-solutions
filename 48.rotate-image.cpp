/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int tmp;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - 1 - i; ++j) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i]; // left to top
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j]; // bottom to left
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i]; // right to bottom
                matrix[j][n - 1 - i] = tmp; // top to right
            }
        }
    }
};
// @lc code=end

