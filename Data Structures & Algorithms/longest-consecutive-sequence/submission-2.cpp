class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen = 0;
        unordered_map<int, int> mp;
        
        for (int num : nums) {
            if (mp.contains(num)) { continue; }

            mp.insert({ num, 1 });
            if (mp.contains(num-1)) {
                mp.at(num) += mp.at(num-1);
            }

            if (mp.contains(num+1)) {
                mp.at(num) += mp.at(num+1);
            }

            if (mp.contains(num-1)) {
                mp.at(num - mp.at(num-1)) = mp[num];
            }
            
            if (mp.contains(num+1)) {
                mp.at(num + mp.at(num+1)) = mp[num];
            }
            maxlen = max(maxlen, mp[num]);
        }

        return maxlen;
    }
};
