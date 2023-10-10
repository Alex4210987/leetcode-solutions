/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int i=0;
        stack<char> st;
        while(i<s.length()){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                if(s[i]==')'&&st.top()!='(') return false;
                if(s[i]==']'&&st.top()!='[') return false;
                if(s[i]=='}'&&st.top()!='{') return false;
                st.pop();
            }
            i++;
        }
        if(st.empty()) return true;
        return false;
    }
};
// @lc code=end

