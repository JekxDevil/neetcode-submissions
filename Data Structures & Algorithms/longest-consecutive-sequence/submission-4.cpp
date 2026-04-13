class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        
        int maxlen = 0;
        // only counts from BEGINNING of sequences
        for (int num : nums) {
            bool isstart = !seen.contains(num-1);
            
            if (!isstart) { continue; }

            int len = 1;
            while (seen.contains(num+len)) {
                len++;
            }

            maxlen = max(maxlen, len);
        }

        return maxlen;
    }
};
