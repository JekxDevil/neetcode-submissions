class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        using Size = std::size_t;
        for (Size i = 0; i < nums.size(); i++) {
            for (Size j = i+1; j < nums.size(); j++) {
                bool sumtotarget = nums[i] + nums[j] == target;
                if (sumtotarget) { 
                    return { i, j };
                }
            }
        }
        return { -1, -1 };
    }
};
