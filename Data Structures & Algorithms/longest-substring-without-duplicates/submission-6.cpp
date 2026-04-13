class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0;
        int maxlen = 0;
        for (int r = 0; r < s.size(); r++) {
            if (mp.contains(s[r]) && mp[s[r]] >= l) {
                l = mp[s[r]] + 1;
            }

            mp[s[r]] = r;
            maxlen = max(maxlen, r-l+1);
        }

        return maxlen;
    }
};
