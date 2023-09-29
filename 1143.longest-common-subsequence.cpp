/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size(), size2 = text2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
        for (int i = 1; i <= size1; ++i) {
            for (int j = 1; j <= size2; ++j)
                dp[i][j] = text1[i - 1] == text2[j - 1] ? dp[i - 1][j - 1] + 1 :
                    max(dp[i - 1][j], dp[i][j - 1]);
        }
        return dp[size1][size2];
    }
};
// @lc code=end

