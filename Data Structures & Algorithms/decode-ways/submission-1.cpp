class Solution {
public:
    vector<int> dp;
    const int INVALID = -1;

    bool isvalid(int num) {
        return 1 <= num && num <= 26;
    }

    int dfs(int i, string& s) {
        if (dp[i] != INVALID) { return dp[i]; }
        if (s.at(i) == '0') { return 0; }

        int count = dfs(i+1, s);

        int twodigits = stoi(s.substr(i, 2));
        if (i + 2 <= s.size() && isvalid(twodigits)) { 
            count += dfs(i+2, s);     
        }

        return dp[i] = count;
    }

    int numDecodings(string s) {
        dp = vector<int>(s.size()+1, INVALID);
        dp[s.size()] = 1;
        return dfs(0, s);
    }
};
