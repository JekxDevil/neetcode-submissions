class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        for (; i < j; i++, j--) {
            while (i < j && !isalnum(s.at(i))) { i++; }
            while (i < j && !isalnum(s.at(j))) { j--; } 

            bool issameletter = tolower(s.at(i)) == tolower(s.at(j));
            if (!issameletter) { return false; }
        }
        


        return true;
    }
};
