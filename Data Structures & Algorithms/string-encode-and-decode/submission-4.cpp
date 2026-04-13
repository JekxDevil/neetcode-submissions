class Solution {
public:

    string encode(vector<string>& strs) {
        string concat = "";
        for (string& s : strs) {
            string buffsz = to_string(s.size());
            concat += buffsz + "#" + s;
        }
        return concat;
    }

    vector<string> decode(string s) {
        vector<string> strs;

        for (int i = 0; i < s.size(); ) {
            
            int j = i;
            while (s.at(j) != '#') {
                j++;
            }

            int sz = stoi(s.substr(i, j-i));
            i = j + 1;

            strs.push_back(s.substr(i, sz));
            i += sz;
        }

        return strs;
    }
};
