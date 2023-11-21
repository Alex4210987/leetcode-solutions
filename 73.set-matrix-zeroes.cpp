/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); if (m == 0) return;
        int n = matrix[0].size(); if (n == 0) return;

        bool firstRow = false, firstCol = false;
        for (int i = 0; i < m; ++i) if (matrix[i][0] == 0) firstCol = true;
        for (int j = 0; j < n; ++j) if (matrix[0][j] == 0) firstRow = true;

        for (int i = 1; i < m; ++i) {// 从第二行开始
            for (int j = 1; j < n; ++j) {// 从第二列开始
                if (matrix[i][j] == 0) {// 如果当前元素为0
                    matrix[i][0] = 0;// 第i行第一个元素置0
                    matrix[0][j] = 0;// 第j列第一个元素置0
                }
            }
        }

        for (int i = 1; i < m; ++i) {// 从第二行开始
            for (int j = 1; j < n; ++j) {// 从第二列开始
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {// 如果第i行第一个元素为0或者第j列第一个元素为0
                    matrix[i][j] = 0;// 当前元素置0
                }
            }
        }

        if (firstCol) {// 如果第一列有0
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;// 第一列置0
        }
        if (firstRow) {// 如果第一行有0
            for (int j = 0; j < n; ++j) matrix[0][j] = 0;// 第一行置0
        }
    }
};
// @lc code=end

