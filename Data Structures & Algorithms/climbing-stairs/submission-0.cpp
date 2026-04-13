class Solution {
public:
    int f(int n) {
        if (n == 0) { return 0; }
        if (n == 1) { return 1; }
        if (n == 2) { return 2; }
        return f(n-1) + f(n-2);
    }

    int climbStairs(int n) {
        return f(n);
    }
};
