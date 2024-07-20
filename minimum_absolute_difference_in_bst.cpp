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
    void inorder(TreeNode *root, vector<int> &vals)
    {
        if (root == NULL)
            return;

        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

public:
    int getMinimumDifference(TreeNode *root)
    {
        vector<int> vals;

        inorder(root, vals);

        int ans = INT_MAX;

        for (int i = 1; i < vals.size(); i++)
        {
            ans = min(ans, vals[i] - vals[i - 1]);
        }

        return ans;
    }
};

// T(n) = O(n)
// S(n) = O(n)