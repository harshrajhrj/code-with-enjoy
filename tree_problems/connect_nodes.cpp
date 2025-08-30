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

vector<string> solve(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    // Connect the nextRight pointers

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (!node)
        {
            node->nextRight = q.front();
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

    // Now store the results
    vector<string> res;
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
    //        5
    //       / \
    //      12   13
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

    vector<string> res = solve(root);

    for (string s : res)
    {
        cout << s << ' ';
    }
    cout << endl;

    return 0;
}