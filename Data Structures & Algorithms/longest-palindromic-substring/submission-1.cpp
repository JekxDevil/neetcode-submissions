class Solution {
public:
    string longestPalindrome(string s) {
        string pal = "";
        
        for (size_t i = 0; i < s.size(); i++) {
            int lx, rx; 
            
            lx = rx = i;
            while (0 <= lx && rx < s.size() && s[lx] == s[rx]) {
                if (rx-lx+1 > pal.size()) {
                    pal = s.substr(lx, rx-lx+1);
                }
                lx--;
                rx++;
            }

            lx = i; rx = i+1;
            while (0 <= lx && rx < s.size() && s[lx] == s[rx]) {
                if (rx-lx+1 > pal.size()) {
                    pal = s.substr(lx, rx-lx+1);
                }
                lx--;
                rx++;
            }
        }

        return pal;
    }
};
