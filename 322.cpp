#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0);
        for (int i = 1; i <= amount; i++) {
            int min = -1;
            for (int j = 0; j < coins.size(); j++) {
                if (i >= coins[j] && dp[i-coins[j]] != -1) {
                    int temp = dp[i-coins[j]] + 1;
                    if (min == -1 || temp < min) {
                        min = temp;
                    }
                }
            }
            dp[i] = min;
        }
        return dp[amount];
    }
};