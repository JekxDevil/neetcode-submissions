class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 1;

        for (int i = 0; i < s.size(); i++) {
            unordered_map<int, int> freq;
            freq[s[i]]++;
            int maxfreq = freq[s[i]];

            for (int j = i + 1; j < s.size(); j++) {
                freq[s[j]]++;
                maxfreq = max(maxfreq, freq[s[j]]);
                
                if (j-i+1 - maxfreq <= k) {
                    maxlen = max(maxlen, j-i+1);
                }
            }
        }
        
        return maxlen;
    }
};
