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

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        if (!root->left && !root->right) {
            return targetSum == root->val;
        }

        bool lSum = hasPathSum(root->left, targetSum - root->val);
        bool rSum = hasPathSum(root->right, targetSum - root->val);

        return lSum || rSum;

    }
};

// T(n) = O(n)
// S(n) = O(n)