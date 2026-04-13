class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size()-2; i++) {
            while (i > 0 && nums[i] == nums[i-1]) { i++; } 
            int l = i + 1;
            int r = nums.size()-1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({ nums[i], nums[l], nums[r] });
                    l++; r--;
                    while (l > i+1 && r < nums.size() && nums[l] == nums[l-1] && nums[r] == nums[r+1]) {
                        l++; r--;
                    }
                } else if (sum < 0) {
                    l++;
                    // while (l > i+1 && nums[l] == nums[l-1] && l < r) { l++; }
                } else {
                    r--;
                    // while (r < nums.size()-1 && nums[r] == nums[r+1] && l < r) { r--; }
                }

            }
        }

        return res;
    }
};
