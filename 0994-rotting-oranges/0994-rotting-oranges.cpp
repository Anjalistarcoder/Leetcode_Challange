class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Find all rotten oranges and count fresh oranges
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        int minutes = 0;

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        // BFS
        while(!q.empty() && fresh > 0)
        {
            int size = q.size();
            minutes++;

            for(int i=0;i<size;i++)
            {
                auto front = q.front();
                q.pop();

                int x = front.first;
                int y = front.second;

                for(int k=0;k<4;k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx>=0 && nx<rows &&
                       ny>=0 && ny<cols &&
                       grid[nx][ny]==1)
                    {
                        grid[nx][ny]=2;
                        fresh--;
                        q.push({nx,ny});
                    }
                }
            }
        }

        if(fresh > 0)
            return -1;

        return minutes;
    }
};