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

bool isValidBST(TreeNode *node)
{
    TreeNode *previousNode = nullptr;

    function<bool(TreeNode *)> inOrderValidate = [&](TreeNode *currentNode) -> bool
    {
        if (!currentNode)
            return true;

        if (!inOrderValidate(currentNode->left))
            return false;
        if (previousNode && previousNode->val >= currentNode->val)
            return false;

        previousNode = currentNode;

        return inOrderValidate(currentNode->right);
    };

    return inOrderValidate(node);
}
int main()
{
    return 0;
}