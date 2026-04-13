class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> factexcl(nums.size(), -1);

        int prefix = 1;
        factexcl[0] = prefix;
        for (int i = 1; i < nums.size(); i++) {
            prefix *= nums[i-1];
            factexcl[i] = prefix;
        }

        int postfix = 1;
        for (int i = nums.size()-2; i >= 0; i--) {
            postfix *= nums[i+1];
            factexcl[i] *= postfix;
        }

        return factexcl;
    }
};
