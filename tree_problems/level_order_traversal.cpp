// https://www.geeksforgeeks.org/dsa/print-level-order-traversal-line-line/
// https://www.geeksforgeeks.org/dsa/connect-nodes-at-same-level/
// https://www.geeksforgeeks.org/dsa/zigzag-tree-traversal/
// https://www.geeksforgeeks.org/dsa/find-level-maximum-sum-binary-tree/
// https://www.geeksforgeeks.org/dsa/maximum-width-of-a-binary-tree/

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

void lot_util(Node *node, int level, vii &res)
{
    // Base cases
    if (node == nullptr)
        return;

    // If no new level is added then add new level
    if (res.size() <= level)
        res.push_back({});

    res[level].push_back(node->data);

    lot_util(node->left, level + 1, res);
    lot_util(node->right, level + 1, res);
}

vii levelOrderTraversal(Node *node)
{
    vii res;
    lot_util(node, 0, res);
    return res;
}

vii levelOrderTraversalQueue(Node *node)
{
    if (node == nullptr)
        return {};

    queue<Node *> q;
    q.push(node);

    int level = 0;
    vii res;

    while (!q.empty())
    {
        int currSize = q.size();
        res.push_back({});

        for (int i = 0; i < currSize; i++)
        {
            Node *front = q.front();
            q.pop();
            res[level].push_back(front->data);
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
        level++;
    }
    return res;
}

void lot_line_line(Node *node)
{

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

    vii lvl = levelOrderTraversal(root); // O(n) time and O(n) space

    for (vi level : lvl)
    {
        cout << "[";
        for (int i = 0; i < level.size(); i++)
        {
            cout << level[i];
            if (i < level.size() - 1)
                cout << ", ";
        }
        cout << "] ";
    }
    cout << endl
         << endl;
    lvl = levelOrderTraversalQueue(root); // O(n) time and O(n) space

    for (vi level : lvl)
    {
        cout << "[";
        for (int i = 0; i < level.size(); i++)
        {
            cout << level[i];
            if (i < level.size() - 1)
                cout << ", ";
        }
        cout << "] ";
    }
}