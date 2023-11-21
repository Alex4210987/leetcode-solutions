/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {     
        if (n == 1) return 1;
        if (n == 2) return 2;

        int a = 1, b = 2, c = 0;
        for (int i = 3; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }
};
// @lc code=end

