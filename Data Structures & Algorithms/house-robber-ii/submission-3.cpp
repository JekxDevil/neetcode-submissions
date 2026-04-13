class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) { return nums.front(); }
        int startincl = getmaxrob(nums, 0, nums.size()-1);
        int endincl = getmaxrob(nums, 1, nums.size());
        return max(startincl, endincl);
    }

    int getmaxrob(vector<int>& v, int start, int end) {
        int prevprev = 0, prev = 0;
        for (int i = start; i < end; i++) {
            int rob = max(v.at(i) + prevprev, prev);
            prevprev = prev;
            prev = rob;
        }
        return prev;
    }
};
