/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for(int i = 0; i < s.size(); i++){
            if(i > 0 && romanCharToInt(s[i]) > romanCharToInt(s[i-1])){
                result += romanCharToInt(s[i]) - 2 * romanCharToInt(s[i-1]);
            }else{
                result += romanCharToInt(s[i]);
            }
        }
        return result;
    }
private:
    int romanCharToInt(char c){
        switch(c){
            case 'I': return 1; break;
            case 'V': return 5; break;
            case 'X': return 10; break;
            case 'L': return 50; break;
            case 'C': return 100; break;
            case 'D': return 500; break;
            case 'M': return 1000; break;
            default: return 0; break;
        }
    }
};
// @lc code=end

