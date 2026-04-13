class Solution {
public:
    const int INVALID = -1;

    bool isvalid(int num) {
        return 1 <= num && num <= 26;
    }


    int numDecodings(string s) {
        vector<int> dp(s.size()+1, INVALID);
        dp[s.size()] = 1;
        for (int i = s.size()-1; i >= 0; i--) {

            if (s.at(i) == '0') { 
                dp[i] = 0; 
                continue; 
            }

            dp[i] = dp[i+1];
            int twodigits = stoi(s.substr(i, 2));
            if (i + 2 <= s.size() && isvalid(twodigits)) {

                dp[i] += dp[i+2];
            }
        }

        return dp[0];
    }
};
