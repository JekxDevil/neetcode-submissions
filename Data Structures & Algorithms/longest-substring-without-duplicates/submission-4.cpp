class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) { return 0; }

        int maxlen = 1;
        for (int i = 0; i < s.size(); i++) {
            unordered_set<char> seen;
            seen.insert(s[i]);
            for (int j = i + 1; j < s.size(); j++) {
                if (seen.contains(s[j])) {
                    break; 
                }

                seen.insert(s[j]);
                maxlen = max(maxlen, j-i+1);
            }
        }

        return maxlen;
    }
};
