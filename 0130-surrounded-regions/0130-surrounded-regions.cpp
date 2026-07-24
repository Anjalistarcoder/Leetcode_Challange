class Solution {
private:
    void dfs(vector<vector<char>>& board, int r, int c, int rows, int cols) {
        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'O') {
            return;
        }
        board[r][c] = 'E'; // Mark as escaped/safe
        dfs(board, r + 1, c, rows, cols);
        dfs(board, r - 1, c, rows, cols);
        dfs(board, r, c + 1, rows, cols);
        dfs(board, r, c - 1, rows, cols);
    }

public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) return;
        int cols = board[0].size();

        // Step 1: Check borders for 'O' and mark connected regions
        for (int r = 0; r < rows; ++r) {
            dfs(board, r, 0, rows, cols);
            dfs(board, r, cols - 1, rows, cols);
        }
        for (int c = 0; c < cols; ++c) {
            dfs(board, 0, c, rows, cols);
            dfs(board, rows - 1, c, rows, cols);
        }

        // Step 2: Update the board
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X'; // Surrounded
                } else if (board[r][c] == 'E') {
                    board[r][c] = 'O'; // Safe
                }
            }
        }
    }
};
