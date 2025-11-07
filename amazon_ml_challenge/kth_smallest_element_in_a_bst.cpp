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

int kthSmallest(TreeNode *node, int k)
{
    stack<TreeNode *> st;

    st.push(node);

    vector<int> result;
    TreeNode *curr = node;

    while (curr || !st.empty())
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            auto inorder = st.top();
            st.pop();
            k--;
            if (k == 0)
                return curr->val;
            curr = curr->right;
        }
    }

    return 0;
}
int main()
{
}