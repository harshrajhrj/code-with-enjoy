// https://www.geeksforgeeks.org/dsa/zigzag-tree-traversal/

#include <bits/stdc++.h>
using namespace std;

#define FOR(x, to) for (x = 0; x < (to); x++)
#define FORI(x, to) for (x; x < (to); x++)
#define FORR(x, arr) for (auto &x : arr)
#define ALL(a) (a.begin(), a.end())
#define mem(a, n) memset(a, n, sizeof(a))

typedef vector<int> vi;
typedef vector<vi> vii;

class Node
{
public:
    int data;
    Node *left, *right;

    // Constructor to initialize a new node
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Calculate height of the tree
int treeHeight(Node *root)
{
    if (!root)
        return 0;
    int lHeight = treeHeight(root->left);
    int rHeight = treeHeight(root->right);
    return max(lHeight, rHeight) + 1;
}

void lefttoright(Node *root, int level, vi &ans)
{
    if (root == nullptr)
        return;

    if (level == 1)
    {
        ans.push_back(root->data);
    }
    else
    {
        lefttoright(root->left, level - 1, ans);
        lefttoright(root->right, level - 1, ans);
    }
}

void righttoleft(Node *root, int level, vi &ans)
{
    if (root == nullptr)
        return;

    if (level == 1)
    {
        ans.push_back(root->data);
    }
    else
    {
        righttoleft(root->right, level - 1, ans);
        righttoleft(root->left, level - 1, ans);
    }
}

void solve_using_recursion(Node *root)
{
    int height = treeHeight(root);
    vi ans;
    bool traverse = true; // left to right traverse flag
    int i = 1;
    FORI(i, height + 1)
    {
        if (traverse)
            lefttoright(root, i, ans);
        else
            righttoleft(root, i, ans);

        traverse = !traverse;
    }

    i = 0;
    FOR(i, ans.size())
    {
        cout << ans[i] << " ";
    }
}

// Using two stacks
// This traversal alternates as we first push right in s2 and first push left in s1.
void solve_using_two_stacks(Node *root)
{
    stack<Node *> s1;
    stack<Node *> s2;

    s1.push(root);
    vi res;

    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            Node *node = s1.top();
            s1.pop();
            res.push_back(node->data);
            if (node->left)
                s2.push(node->left);
            if (node->right)
                s2.push(node->right);
        }
        while (!s2.empty())
        {
            Node *node = s2.top();
            s2.pop();
            res.push_back(node->data);
            if (node->right)
                s1.push(node->right);
            if (node->left)
                s1.push(node->left);
        }
    }

    int i = 0;
    FOR(i, res.size())
    {
        cout << res[i] << " ";
    }
}
// Using deque
void solve_using_deque(Node *root) {
    
}

int main()
{
    //        5
    //       / \
    //     12   13
    //     / \    \
    //    7   14    2
    //   / \  / \  / \
    //  17 23 27 3 8  11

    Node *root = new Node(5);
    root->left = new Node(12);
    root->right = new Node(13);

    root->left->left = new Node(7);
    root->left->right = new Node(14);

    root->right->right = new Node(2);

    root->left->left->left = new Node(17);
    root->left->left->right = new Node(23);

    root->left->right->left = new Node(27);
    root->left->right->right = new Node(3);

    root->right->right->left = new Node(8);
    root->right->right->right = new Node(11);

    solve_using_two_stacks(root);
}