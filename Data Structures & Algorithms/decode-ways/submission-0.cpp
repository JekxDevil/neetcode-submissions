class Solution {
public:
    bool isvalid(int num) {
        return 1 <= num && num <= 26;
    }

    int dfs(int i, const string& s) {
        if (i == s.size()) { return 1; }
        if (s.at(i) == '0') { return 0; }

        int count = dfs(i+1, s);

        int twodigits = stoi(s.substr(i, 2));
        if (i + 2 <= s.size() && isvalid(twodigits)) { 
            count += dfs(i+2, s);     
        }

        return count;
    }

    int numDecodings(string s) {
        return dfs(0, s);
    }
};
