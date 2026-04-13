class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> close2open = { 
            { ')', '(' },
            { ']', '[' },
            { '}', '{' }
        };

        stack<char> buff;
        for (char c : s) {
            bool isopen = c == '(' || c == '{' || c == '[';
            if (isopen) { 
                buff.push(c);
                continue;
            }

            bool invalidclose = !isopen && buff.size() == 0;
            if (invalidclose) { return false; }

            bool unmatching = !isopen && buff.top() != close2open[c];
            if (unmatching) { return false; }

            buff.pop();
        }

        if (buff.size() > 0) { return false; }

        return true;
    }
};
