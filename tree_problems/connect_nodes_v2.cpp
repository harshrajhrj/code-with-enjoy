// For any tree, using recusrion O(N) -> Time and O(h) -> Space
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
    Node *left, *right, *nextRight;

    // Constructor to initialize a new node
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
        nextRight = nullptr;
    }
};

Node *findNextRight(Node *node)
{
    Node *temp = node->nextRight;

    while (temp)
    {
        // Case 1
        //           1
        //         /   \
        //        2     3
        //      /  \   /  \
        //     3    3 3    3
        if (temp->left)
            return temp->left;
        if (temp->right)
            return temp->right;

        temp = temp->nextRight;
    }
    return nullptr;
}

void connectNodes(Node *root)
{
    if (root == nullptr)
        return;

    if (root->left)
    {
        if (root->right)
        {
            root->left->nextRight = root->right;
        }
        else
        {
            root->left->nextRight = findNextRight(root);
        }
    }
    if (root->right)
    {
        root->right->nextRight = findNextRight(root);
    }
}

vector<string> solve(Node *root)
{
    // Now store the results
    vector<string> res;

    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node)
        {
            res.push_back(to_string(node->data));
            if (node->nextRight == nullptr)
                res.push_back("#");

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(nullptr);
        }
    }

    return res;
}

int main()
{
    // Constructed binary tree is
    //       10
    //      / \
    //     8   2
    //    /
    //   3

    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);

    connectNodes(root);

    vector<string> res = solve(root);
    for (const string &s : res)
    {
        cout << s << ' ';
    }
    cout << endl;

    return 0;
}