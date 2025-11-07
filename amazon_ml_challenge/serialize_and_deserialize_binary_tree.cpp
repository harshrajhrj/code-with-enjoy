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

string serialize(TreeNode *root)
{
    if (!root)
        return "#";
    queue<TreeNode *> q;

    q.push(root);

    string str = "";

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            str += to_string(node->val) + "# ";

            if (node->left)
                q.push(node->left);
            else
                str += "# ";

            if (node->right)
                q.push(node->right);
            else
                str += "# ";
        }
    }

    str.pop_back();
    return str;
}

TreeNode *deserialize(string s)
{
    if (s.empty())
        return nullptr;

    stringstream stringStream(s);
    string token;

    stringStream >> token;

    TreeNode *root = new TreeNode(stoi(token));

    queue<TreeNode *> parentQueue;
    parentQueue.push(root);

    while (!parentQueue.empty())
    {
        TreeNode *parentNode = parentQueue.front();
        parentQueue.pop();

        stringStream >> token;
        if (token != "#")
        {
            TreeNode *left = new TreeNode(stoi(token));
            parentNode->left = left;
        }

        stringStream >> token;
        if (token != "#")
        {
            TreeNode *right = new TreeNode(stoi(token));
            parentNode->right = right;
        }
    }

    return root;
}

int main()
{
    return 0;
}