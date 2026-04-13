class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int l = 0;
        unordered_set<char> seen;
        for (int r = 0; r < s.size(); r++) {
            while (seen.contains(s[r])) {
                seen.erase(s[l]);
                l++;
            }

            seen.insert(s[r]);
            maxlen = max(maxlen, (int)seen.size());
        }

        return maxlen;
    }
};
