class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 1;
        const int K = k;
        vector<int> count(26, 0);

        int l, r;
        l = r = 0;
        count[s[0]-'A']++;

        while (l <= r) {
            int wndsz = r-l+1;
            int mostfreq = *max_element(count.begin(), count.end());
            bool suffreplaces = wndsz - mostfreq <= k;
            if (suffreplaces) {
                maxlen = max(maxlen, wndsz);

                if (r < s.size()) {
                    r++;
                    count[s[r]-'A']++;
                }
            } else {
                count[s[l]-'A']--;
                l++;
            }

            if (r == s.size()) { break; }
        }

        return maxlen;
    }
};
