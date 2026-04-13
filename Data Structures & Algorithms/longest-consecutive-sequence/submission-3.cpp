class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) { seen.insert(num); }
        
        int maxlen, len; maxlen = len = 0;
        // only counts from BEGINNING of sequences
        for (int num : nums) {
            bool isstart = !seen.contains(num-1);
            
            if (!isstart) { continue; }

            len = 1;
            while (seen.contains(num+len)) {
                len++;
            }

            maxlen = max(maxlen, len);
        }

        return maxlen;
    }
};
