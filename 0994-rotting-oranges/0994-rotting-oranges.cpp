class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Count fresh oranges and push all rotten oranges into queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        if (fresh == 0)
            return 0;

        int minutes = 0;
        vector<pair<int, int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while (!q.empty()) {
            int sz = q.size();
            bool changed = false;

            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto d : dir) {
                    int nx = x + d.first;
                    int ny = y + d.second;

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                        grid[nx][ny] == 1) {

                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                        changed = true;
                    }
                }
            }

            if (changed)
                minutes++;
        }

        return (fresh == 0) ? minutes : -1;
    }
};