class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = { 0 };
        int cols[9] = { 0 };
        int squares[9] = { 0 };

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') { continue; }

                int num = board[r][c] - '1';
                int mask = 1 << num;
                bool invalidrow = mask & rows[r];
                bool invalidcol = mask & cols[c];

                int sqidx = r/3*3 + c/3;
                bool invalidsquare = mask & squares[sqidx];

                if (invalidrow || invalidcol || invalidsquare) { return false; }

                rows[r] |= mask;
                cols[c] |= mask;
                squares[sqidx] |= mask;
            }
        }
        
        return true;
    }
};
