class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) { return nums.front(); }
        
        vector<int> 
            dp1(nums.size(), -1), 
            dp2(nums.size(), -1);
        
        dp1[0] = dp2[0] = 0;

        // end excluded
        dp1[1] = nums[0];
        for (int i = 2; i < nums.size(); i++) {
            int prev = dp1[i-1];
            int cur = nums[i-1] + dp1[i-2];
            dp1[i] = max(prev, cur);
        }

        // start excluded
        dp2[1] = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            int prev = dp2[i-1];
            int cur = nums[i] + dp2[i-2];
            dp2[i] = max(prev, cur);
        }

        return max(dp1.back(), dp2.back());
    }
};
