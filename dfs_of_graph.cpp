#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &ans)
    {
        vis[node] = true;
        ans.push_back(node);

        for (auto it : adj[node])
        {
            if (!vis[it])
                dfs(it, adj, vis, ans);
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V, false);
        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, ans);
            }
        }

        return ans;
    }
};

// T(O) = O(V+E)
// S(O) = O(V)