class Solution {
public:

    bool safe(int row, int col, vector<string>& board, int n) {

        // upper-left diagonal
        int r = row;
        int c = col;

        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q')
                return false;

            r--;
            c--;
        }

        // left side
        r = row;
        c = col;

        while (c >= 0) {
            if (board[r][c] == 'Q')
                return false;

            c--;
        }

        // lower-left diagonal
        r = row;
        c = col;

        while (r < n && c >= 0) {
            if (board[r][c] == 'Q')
                return false;

            r++;
            c--;
        }

        return true;
    }

    void solve(vector<vector<string>>& ans,
               vector<string>& board,
               int idx,
               int n) {

        // All columns filled
        if (idx == n) {
            ans.push_back(board);
            return;
        }

        // Try every row in this column
        for (int r = 0; r < n; r++) {

            if (safe(r, idx, board, n)) {

                board[r][idx] = 'Q';

                solve(ans, board, idx + 1, n);

                board[r][idx] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        solve(ans, board, 0, n);

        return ans;
    }
};