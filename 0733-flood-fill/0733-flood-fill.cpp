class Solution {
public:

    void dfs(vector<vector<int>>& image,
             int row,
             int col,
             int oldColor,
             int newColor)
    {
        // Out of bounds
        if(row < 0 || row >= image.size() ||
           col < 0 || col >= image[0].size())
            return;

        // Different color
        if(image[row][col] != oldColor)
            return;

        // Color the current cell
        image[row][col] = newColor;

        // Visit 4 directions
        dfs(image, row - 1, col, oldColor, newColor); // Up
        dfs(image, row + 1, col, oldColor, newColor); // Down
        dfs(image, row, col - 1, oldColor, newColor); // Left
        dfs(image, row, col + 1, oldColor, newColor); // Right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr,
                                  int sc,
                                  int color)
    {
        int oldColor = image[sr][sc];

        // No need to change anything
        if(oldColor == color)
            return image;

        dfs(image, sr, sc, oldColor, color);

        return image;
    }
};