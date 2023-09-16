class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];
        
        for (int i = 1; i < n; i++) {
            int temp = maxProd;
            maxProd = max(maxProd * nums[i], max(nums[i], minProd * nums[i]));
            minProd = min(minProd * nums[i], min(nums[i], temp * nums[i]));
            ans = max(ans, maxProd);
        }
        
        return ans;
    }
};