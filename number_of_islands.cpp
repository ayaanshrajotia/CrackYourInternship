class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = true;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        for (int k = 0; k < 4; k++)
        {
            int row = drow[k] + i;
            int col = dcol[k] + j;

            if (row >= 0 && row < n && col >= 0 && col < m && !vis[row][col] && grid[row][col] == '1')
            {
                dfs(grid, row, col, vis);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, (vector<bool>(m, false)));
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    dfs(grid, i, j, vis);
                    count++;
                }
            }
        }
        return count;
    }
};