/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include<vector>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        generate(res, s, n, n);
        return res;
    }
    void generate(vector<string>& res, string s, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(s);
            return;
        }
        if (left > 0) {
            generate(res, s + "(", left - 1, right);
        }
        if (right > left) {
            generate(res, s + ")", left, right - 1);
        }
    }
};
// @lc code=end

