class Solution {
public:
    int characterReplacement(string s, int k) {
        int l, r;
        l = r = 0;
        unordered_map<int, int> count;
        int maxfreq, maxlen;
        maxlen = maxfreq = ++count[s[r]];

        while (l <= r && r < s.size()) {
            int wndsz = r-l+1;
            if (wndsz - maxfreq <= k) {
                maxlen = max(maxlen, wndsz);
                r++;
                count[s[r]]++;
                maxfreq = max(maxfreq, count[s[r]]);
            } else {
                count[s[l]]--;
                l++;
                if (l > r && r < s.size()) {
                    r = l + 1;
                    count[s[r]]++;
                    maxfreq = max(maxfreq, count[s[r]]);
                }
            }
        }

        return maxlen;
    }
};
