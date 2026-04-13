class Solution {
public:

    string encode(vector<string>& strs) {
        string concat = "";
        for (string& s : strs) {
            concat.append(s);
            concat.append(1, '\0');
        }
        return concat;
    }

    vector<string> decode(string s) {
        vector<string> strs;

        string buff = "";
        for (int i = 0; i < s.size(); i++) {
            if (s.at(i) == '\0') { 
                strs.push_back(buff);
                buff = "";
            } else {
                buff.append(1, s.at(i));
            }
        }

        return strs;
    }
};
