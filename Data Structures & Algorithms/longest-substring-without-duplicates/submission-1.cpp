class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) { return 0; }

        unordered_set<char> seen;
        int maxlen = 1;
        int l = 0;
        int r = l + 1;
        seen.insert(s[l]);
        while (l < r) {
            if (seen.contains(s[r])) {
                seen.erase(s[l]);
                l++;
                if (l == r && r < s.size()) { 
                    r++;
                    seen.insert(s[l]);
                }
            } else {
                seen.insert(s[r]);
                if (r < s.size()) {
                    r++;
                } else {
                    l++;
                }
                maxlen = max(maxlen, r-l);
            }
        }

        return maxlen;
    }
};
