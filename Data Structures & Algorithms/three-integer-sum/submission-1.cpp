class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set< vector<int> >  res;

        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                int b = nums[j];
                for (int k = j + 1; k < nums.size(); k++) {
                    int c = nums[k];
                    bool is3sum = a + b + c == 0;
                    if (!is3sum) { continue; }
                    res.insert({ a, b, c });
                }
            }
        }

        return vector< vector<int> >(res.begin(), res.end());
    }
};
