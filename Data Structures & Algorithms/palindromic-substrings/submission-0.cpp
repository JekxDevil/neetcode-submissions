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
        int count = 0;
        for (int sz = s.size(); sz > 0; sz--) {
            for (int wnd = 0; wnd < s.size()-sz+1; wnd++) {
                if (ispal(s.substr(wnd, sz))) { count++; }
            }
        }
        return count;
    }
};
