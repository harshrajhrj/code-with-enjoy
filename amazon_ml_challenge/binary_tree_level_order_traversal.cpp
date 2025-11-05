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

vector<vector<int>> traverse(TreeNode *root)
{
    vector<vector<int>> result;
    if (!root)
        return result;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        vector<int> currentLevel;
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++)
        {
            TreeNode *root = q.front();
            q.pop();
            currentLevel.push_back(root->val);

            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }

        result.push_back(currentLevel);
    }

    return result;
}

int main()
{
    return 0;
}