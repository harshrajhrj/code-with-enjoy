// For any tree, using recusrion O(N) -> Time and O(1) -> Space
#include <bits/stdc++.h>
using namespace std;

#define FOR(x, to) for (x = 0; x < (to); x++)
#define FORI(x, to) for (x; x < (to); x++)
#define FORR(x, arr) for (auto &x : arr)
#define ALL(a) (a.begin(), a.end())
#define mem(a, n) memset(a, n, sizeof(a))

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
    if (!root)
        return;

    root->nextRight = nullptr;

    while (root)
    {
        Node *q = root;

        // Traverse all nodes at the current level
        // ensures that nextRight at current level is set for all nodes
        while (q)
        {
            if (q->left)
            {
                if (q->right)
                {
                    q->left->nextRight = q->right;
                }
                else
                {
                    q->left->nextRight = findNextRight(q);
                }
            }
            if (q->right)
            {
                q->right->nextRight = findNextRight(q);
            }
            q = q->nextRight;
        }

        // Moving to the next level starting with leftmost node
        if (root->left)
            root = root->left;
        else if (root->right)
            root = root->right;
        else
            root = findNextRight(root);
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
    //           5
    //          / \
    //      12       13
    //     / \       / \
    //    7   14    1   2
    //   / \  / \  / \
    //  17 23 27 3 8  11

    Node *root = new Node(5);
    root->left = new Node(12);
    root->right = new Node(13);

    root->left->left = new Node(7);
    root->left->right = new Node(14);

    root->right->left = new Node(1);
    root->right->right = new Node(2);

    root->left->left->left = new Node(17);
    root->left->left->right = new Node(23);

    // root->left->right->left = new Node(27);
    // root->left->right->right = new Node(3);

    root->right->left->left = new Node(8);
    root->right->left->right = new Node(11);

    connectNodes(root);

    vector<string> res = solve(root);
    for (const string &s : res)
    {
        cout << s << ' ';
    }
    cout << endl;
}