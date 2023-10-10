/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int max_len = 1, start = 0;
        for (int i = 0; i < n; ++i) dp[i][i] = true;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                max_len = 2;
                start = i;
            }
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i < n - len + 1; ++i) {
                int j = i + len - 1;
                if (j >= n) break;
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    max_len = len;
                    start = i;
                }
            }
        }
        return s.substr(start, max_len);   
    }
};
// @lc code=end