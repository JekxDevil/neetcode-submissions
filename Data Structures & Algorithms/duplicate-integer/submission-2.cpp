class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> occs;
        for (int& ch : nums) {
            occs[ch]++;
            if (occs[ch] <= 1) { continue; }
            return true;
        }
        return false;
    }
};