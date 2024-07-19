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
    int ans = 0;

    int diameterOfBinaryTree(TreeNode *root)
    {
        height(root);
        return ans;
    }

    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        ans = max(ans, left + right);

        return max(left, right) + 1;
    }
};

// T(n) = O(n)
// S(n) = O(n)