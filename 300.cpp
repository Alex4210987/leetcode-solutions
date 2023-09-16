#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int i,j=0;
        vector<int> dp(nums.size(),1);
        for (i=1;i<nums.size();i++){
            for (j=0;j<i;j++){
                if (nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int res=0;
        for (i=0;i<nums.size();i++){
            res=max(res,dp[i]);
        }
        return res;
    }
};