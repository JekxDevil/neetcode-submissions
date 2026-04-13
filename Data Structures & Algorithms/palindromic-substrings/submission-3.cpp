class Solution {
public:

    int countSubstrings(string s) {
        int count = s.size();
        int lx, rx;
        for (int i = 0; i < s.size(); i++) {
            // odd case
            lx = i-1; rx = i+1;
            while (0 <= lx && rx < s.size()) {
                if (s[lx] != s[rx]) { break; }
                count++;
                lx--; rx++;
            }

            // even case
            lx = i; rx = i+1;
            while (0 <= lx && rx < s.size()) {
                if (s[lx] != s[rx]) { break; }
                count++;
                lx--; rx++;
            }
        }

        return count;
    }
};
