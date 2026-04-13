class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> dict;
        for (int& el : nums) { dict[el]++; }

        multimap<int, int, greater<int> > freq2el;
        for (auto& [num, freq] : dict) {
            freq2el.insert({ freq, num });
        }

        vector<int> topkfreqs;
        auto beg = freq2el.begin();
        while(k--) {
            auto& [freq, num] = *beg;
            topkfreqs.push_back(num);
            beg++;
        }

        return topkfreqs;
    }
};
