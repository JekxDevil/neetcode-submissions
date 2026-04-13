class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1);
        dp[0] = 0;
        dp[1] = nums[0];
        for (size_t i = 2; i <= nums.size(); i++) {
            int prev = dp[i-1];
            int cur = nums[i-1] + dp[i-2];
            dp[i] = max(prev, cur);
        }
        return dp[nums.size()];
    }
};
