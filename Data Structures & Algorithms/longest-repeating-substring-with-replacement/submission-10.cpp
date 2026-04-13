class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        unordered_map<int, int> count;
        int maxfreq, maxlen;
        maxlen = maxfreq = 0;

        for (int r = 0; r < s.size(); r++) {
            // set iter counter tracks
            int wndsz = r-l+1;
            count[s[r]]++;
            maxfreq = max(maxfreq, count[s[r]]);

            // shrink while not valid until valid again
            while (wndsz - maxfreq > k) {
                count[s[l]]--;
                l++;
                wndsz = r-l+1;
            }

            // get desired result
            maxlen = max(maxlen, wndsz);
        }

        return maxlen;
    }
};
