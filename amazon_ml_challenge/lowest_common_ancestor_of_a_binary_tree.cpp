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

TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
        return nullptr;
    else if (root == p)
        return p;
    else
        return q;

    // traverse left subtree...
    TreeNode *l1 = lca(root->left, p, q);
    TreeNode *l2 = lca(root->right, p, q);
    // if both left and right subtree returns a value then we have found
    // p and q which means the current node is our LCA
    if (l1 && l2)
        return root;

    //         2
    //       /   \
    //     3       4
    //   /  \    /   \
    //  5    7  8     9
    // p = 3 & q = 5...earliest return 5
    return l1 ? l1 : l2;
}

int main()
{
    return 0;
}