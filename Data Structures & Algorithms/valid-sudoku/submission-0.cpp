class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<bool> present(10, false);
            for(int j = 0; j < 9; j++) {
                if (board[i][j] == '.') { continue; }

                int num = board[i][j] - '0';
                bool invalid = present.at(num);
                if (invalid) { return false; }

                present[num] = true;
            }
        }

        for (int i = 0; i < 9; i++) {
            vector<bool> present(10, false);
            for(int j = 0; j < 9; j++) {
                if (board[j][i] == '.') { continue; }

                int num = board[j][i] - '0';
                bool invalid = present.at(num);
                if (invalid) { return false; }

                present[num] = true;
            }
        }

        for (int i = 0; i < 9; i++) {
            vector<bool> present(10, false);
            for(int j = 0; j < 9; j++) {

                int a = i/3*3 + j/3;
                int b = i%3*3 + j%3;
                if (board[a][b] == '.') { continue; }

                int num = board[a][b] - '0';
                bool invalid = present.at(num);
                if (invalid) { return false; }

                present[num] = true;
            }
        }

        return true;
    }
};
