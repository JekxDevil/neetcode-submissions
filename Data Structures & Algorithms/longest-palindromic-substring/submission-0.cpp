class Solution {
public:
    string longestPalindrome(string s) {
        for (int sz = s.size(); sz >= 1; sz--) {
            for (int wnd = 0; wnd < s.size()-sz+1; wnd++) {
                stack<char> pal;
                string palindrome = s.substr(wnd, sz);
                bool check = true;
                for (int i = wnd; i < wnd+sz; i++) {
                    pal.push(s[i]);
                }

                for (int i = wnd; i < wnd+sz; i++) {
                    if (s[i] == pal.top()) { 
                        pal.pop();
                    } else {
                        check = false;
                    }
                }

                if (check) { return palindrome; }
            }
        }
        return "";
    }
};
