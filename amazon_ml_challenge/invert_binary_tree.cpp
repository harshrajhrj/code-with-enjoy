#include <bits/stdc++.h>
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

TreeNode *invert(TreeNode *root)
{
    if (!root)
        return nullptr;

    TreeNode *leftSubTree = invert(root->left);
    TreeNode *rightSubTree = invert(root->right);

    // swap(leftSubTree, rightSubTree);

    root->left = rightSubTree;
    root->right = leftSubTree;

    return root;
}
int main()
{
    return 0;
}