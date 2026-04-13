class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) { return false; }
        
        std::priority_queue<char> a, b;
        for (char& c : s) { a.push(c); }
        for (char& c : t) { b.push(c); }

        while (!a.empty() && !b.empty()) {
            bool isdiff = a.top() != b.top();
            if (isdiff) { return false; }
            a.pop();
            b.pop();
        }
        return true;
    }
};
