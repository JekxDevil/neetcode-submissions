class Solution {
public:
    vector<int> dp;

    int f(int n) {
        if (n == 1) { return 1; }
        if (n == 2) { return 2; }

        if (dp[n] != -1) { return dp[n]; }

        dp[n] = f(n-1) + f(n-2);
        return dp[n];
    }

    int climbStairs(int n) {
        // dp = vector<int>(n+1, -1);
        // return f(n);
        dp = vector<int>(n+1, -1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < n+1; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
