/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int maxLen = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (map.find(s[i]) != map.end()) {
                start = max(start, map[s[i]] + 1);
            }
            map[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};
// @lc code=end

