/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> pre(n, 1);
        int cur;
        int i,j;
        for(i=1;i<m;i++){
            cur = pre[0] = 1;
            for(j=1;j<n;j++){
                cur += pre[j];
                pre[j] = cur;
            }
        }
        return pre[n-1];
    }
};
// @lc code=end