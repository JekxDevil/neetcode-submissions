class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 0;
        unordered_set<char> charset(s.begin(), s.end());

        for (char c : charset) {
            int l, r;
            l = r = 0;
            int notc = s[r] != c;
            while (l <= r && r < s.size()) {
                
                int wndsz = r-l+1;
                if (notc <= k) {
                    maxlen = max(maxlen, wndsz);
                    r++;
                    notc += s[r] != c;
                } else {
                    notc -= s[l] != c;
                    l++;
                    if (l > r && r < s.size()) {
                        r = l + 1;
                        notc += s[r] != c;
                    }
                }

            }
        }

        return maxlen;
    }
};
