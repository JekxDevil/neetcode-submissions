class Solution {
public:

    string encode(vector<string>& strs) {
        string concat = "";
        for (string& s : strs) {
            string buffsz = to_string(s.size());
            concat.append(buffsz);
            concat.append("#");
            concat.append(s);
        }
        return concat;
    }

    vector<string> decode(string s) {
        vector<string> strs;

        int sz = -1;
        string buffsz = "";
        for (int i = 0; i < s.size(); ) {

            while (s.at(i) != '#') {
                buffsz.append(1, s.at(i));
                i++;
            }

            i++;

            sz = stoi(buffsz);
            buffsz = "";
            strs.push_back(s.substr(i, sz));
            i += sz;
        }

        return strs;
    }
};
