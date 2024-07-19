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
    bool match(TreeNode *lRoot, TreeNode *rRoot)
    {
        if (lRoot == NULL && rRoot == NULL)
            return true;
        if (lRoot == NULL || rRoot == NULL)
            return false;

        return (lRoot->val == rRoot->val) && match(lRoot->left, rRoot->right) && match(lRoot->right, rRoot->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;

        return match(root->left, root->right);
    }
};

// T(n) = O(n)
// S(n) = O(n)