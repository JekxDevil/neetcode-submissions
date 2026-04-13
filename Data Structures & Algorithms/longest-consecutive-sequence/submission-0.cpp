class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int, less<int>> myset;
        for (int el : nums) {
            myset.insert(el);
        }

        if (myset.empty()) { return 0; }
        
        int maxlength, length;
        maxlength = length = 1;
        int prev = *myset.begin();

        for (int el : myset) {

            if (el == prev+1) { 
                length++;
                prev = el;
                continue;
            }

            maxlength = max(maxlength, length);
            length = 1;
            prev = el;
        }

        maxlength = max(maxlength, length);
        return maxlength;
    }
};
