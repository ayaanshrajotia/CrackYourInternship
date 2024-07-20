#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        q.push(root);
        int mode = 1;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);

                level.push_back(node->val);
            }
            if (mode % 2 == 0)
                reverse(level.begin(), level.end());
            mode++;
            ans.push_back(level);
        }
        return ans;
    }
};

// T(n) = O(n)
// S(n) = O(n)