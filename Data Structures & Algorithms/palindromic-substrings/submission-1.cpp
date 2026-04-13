class Solution {
public:
    bool ispal(const string& sub) {
        int l = 0; 
        int r = sub.size()-1;
        while (l < sub.size() && r >= 0) {
            if (sub[l] != sub[r]) { return false; }
            l++; r--;
        }
        return true;
    }

    int countSubstrings(string s) {
        int count = s.size();
        int lx, rx;
        for (int i = 0; i < s.size(); i++) {
            // odd case
            lx = i-1; rx = i+1;
            while (0 <= lx && rx < s.size()) {
                if (ispal(s.substr(lx, rx-lx+1))) { count++; }
                lx--; rx++;
            }

            // even case
            lx = i; rx = i+1;
            while (0 <= lx && rx < s.size()) {
                if (ispal(s.substr(lx, rx-lx+1))) { count++; }
                lx--; rx++;
            }
        }

        return count;
    }
};
