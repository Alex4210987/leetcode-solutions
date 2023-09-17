/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> m1(26, 0), m2(26, 0);
        if(s1.size()>s2.size()){
            return false;
        }
        for(int i=0;i<s1.size();i++){
            m1[s1[i]-'a']++;
            m2[s2[i]-'a']++;
        }
        if(m1==m2){
            return true;
        }
        for(int i=s1.size();i<s2.size();i++){
            m2[s2[i-s1.size()]-'a']--;
            m2[s2[i]-'a']++;
            if(m1==m2){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end