class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_set<string> checkin;

        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            for (int j = i+1; j < nums.size(); j++) {
                int b = nums[j];
                for (int k = j+1; k < nums.size(); k++) {
                    int c = nums[k];
                    bool is3sum = a + b + c == 0;
                    if (!is3sum) { continue; }

                    vector<int> v = { a, b, c };
                    sort(v.begin(), v.end());
                    string key = to_string(v[0]) + "," + to_string(v[1]) + "," + to_string(v[2]);

                    if (checkin.contains(key)) { continue; }

                    res.push_back({ v[0], v[1], v[2] });
                    checkin.insert(key);
                }
            }
        }

        return res;
    }
};
