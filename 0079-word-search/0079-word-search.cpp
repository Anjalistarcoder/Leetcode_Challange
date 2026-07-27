class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        // Try starting the search from every cell in the grid
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int index) {
        // Base Case: If the entire word is matched
        if (index == word.length()) {
            return true;
        }
        
        // Boundary check and matching character check
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }
        
        // Save current character to restore it later
        char temp = board[r][c];
        
        // Mark the current cell as visited using a placeholder character
        board[r][c] = '#';
        
        // Explore all 4 adjacent directions (up, down, left, right)
        bool found = dfs(board, word, r + 1, c, index + 1) ||
                     dfs(board, word, r - 1, c, index + 1) ||
                     dfs(board, word, r, c + 1, index + 1) ||
                     dfs(board, word, r, c - 1, index + 1);
        
        // Backtrack: Restore the original character for other search paths
        board[r][c] = temp;
        
        return found;
    }
};
