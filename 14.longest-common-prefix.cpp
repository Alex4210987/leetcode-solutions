/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string example = strs[0];
        int m = strs.size();
        for(auto i = 1; i < m; i++){
            int n = strs[i].size();
            int j = 0;
            for(; j < n; j++){
                if(example[j] != strs[i][j]){
                    break;
                }
            }
            example = example.substr(0, j);
        }
        return example;
    }
};
// @lc code=end

