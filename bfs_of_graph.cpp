#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    void bfs(int r, int c, vector<vector<int>> &image, int color, vector<vector<bool>> &vis, int oldColor, int n, int m)
    {
        vis[r][c] = true;
        image[r][c] = color;

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++)
        {
            int row = drow[i] + r;
            int col = dcol[i] + c;

            if (row >= 0 && row < n && col >= 0 && col < m && !vis[row][col] && image[row][col] == oldColor)
            {
                bfs(row, col, image, color, vis, oldColor, n, m);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        bfs(sr, sc, image, color, vis, oldColor, n, m);

        return image;
    }
};

// T(n) = O(n*m)
// S(n) = O(n*m)