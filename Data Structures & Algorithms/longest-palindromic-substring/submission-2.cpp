class Solution {
public:
    string longestPalindrome(string s) {
        int reslx, resrx;
        reslx = resrx = 0;
        
        for (size_t i = 0; i < s.size(); i++) {
            int lx, rx; 
            
            lx = rx = i;
            while (0 <= lx && rx < s.size() && s[lx] == s[rx]) {
                if (rx-lx+1 > resrx-reslx+1) {
                    reslx = lx;
                    resrx = rx;
                }
                lx--;
                rx++;
            }

            lx = i; rx = i+1;
            while (0 <= lx && rx < s.size() && s[lx] == s[rx]) {
                if (rx-lx+1 > resrx-reslx+1) {
                    reslx = lx;
                    resrx = rx;
                }
                lx--;
                rx++;
            }
        }

        return s.substr(reslx, resrx-reslx+1);
    }
};
