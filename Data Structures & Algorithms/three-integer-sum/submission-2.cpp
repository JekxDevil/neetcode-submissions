class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map< int, int > mp;
        for (int num : nums) { mp[num]++; }

        vector<vector<int>>  res;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            mp[a]--;

            if (i > 0 && nums[i] == nums[i-1]) { continue; }

            for (int j = i + 1; j < nums.size(); j++) {
                int b = nums[j];
                mp[b]--;

                if (j > i+1 && nums[j] == nums[j-1]) { continue; }

                if (mp[-a-b] <= 0) { continue; }
                
                res.push_back({ a, b, -a-b });
            }

            for (int j = i + 1; j < nums.size(); j++) { mp[nums[j]]++; }
        }

        return res;
    }
};
