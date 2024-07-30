//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>& mat, int i, int j, vector<vector<bool>>& vis, string temp, vector<string>& ans) {
        int n = mat.size();
        
        if (i == n-1 && j == n-1) {
            ans.push_back(temp);
            vis[i][j] = false;
            return;
        }        
        
        vis[i][j] = true;
        
         vector<vector<int>> val = {{1,0,'D'},{0,1,'R'},{0,-1,'L'},{-1,0,'U'}};
        
        for (int k=0; k<4; k++) {
            int row = i + val[k][0];
            int col = j + val[k][1];

            
            if (row >= 0 && row < n && col >= 0 && col < n && !vis[row][col] && mat[row][col] == 1) {
                temp.push_back(val[k][2]);
                dfs(mat, row, col, vis, temp, ans);    
                temp.pop_back();
            }
        }
        
        vis[i][j] = false;
    }
  
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<string> ans;
        
        if (mat[0][0] == 0 || mat[n-1][m-1] == 0) return {};
        
        if (mat[0][0] == 1)
            dfs(mat, 0, 0, vis, "", ans);
            
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends