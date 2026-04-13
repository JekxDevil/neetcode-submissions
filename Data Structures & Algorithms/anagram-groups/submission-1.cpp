class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        using WordIdx = std::pair<string, int>;
        vector<WordIdx> strsidx(strs.size());
        for (size_t i = 0; i < strs.size(); i++) {
            strsidx[i] = { string(strs[i]), i };
        }

        for (size_t i = 0; i < strsidx.size(); i++) {
            sort(strsidx[i].first.begin(), strsidx[i].first.end());
        }
        sort(strsidx.begin(), strsidx.end());

        vector<vector<string>> groups;
        groups.push_back({ strs[strsidx[0].second] });
        for (size_t i = 1; i < strsidx.size(); i++) {
            bool samegroup = strsidx[i].first == strsidx[i-1].first;
            if (samegroup) {
                groups.back().push_back(strs[strsidx[i].second]);
            } else {
                groups.push_back( { strs[strsidx[i].second] } );
            }
        }

        return groups;
    }
};
