class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> 
            cumleft(nums.size() + 1), 
            cumright(nums.size() + 1);
        
        cumleft[0] = cumright[nums.size()] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            cumleft[i] = nums[i-1] * cumleft[i-1];
        }

        for (int i = nums.size()-1; i >= 0; i--) {
            cumright[i] = nums[i] * cumright[i+1];
        }

        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            res[i] = cumleft[i] * cumright[i+1];
        }

        return res;
    }
};
