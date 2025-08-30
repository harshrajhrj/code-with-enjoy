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

int findHeight(Node *root)
{
    if (root == nullptr)
        return -1;

    int leftSubtree = 1 + findHeight(root->left);
    int rightSubtree = 1 + findHeight(root->right);

    return max(leftSubtree, rightSubtree);
}

int findHeightQueue(Node *root)
{
    queue<Node *> q;
    q.push(root);

    int depth = 0;

    while (!q.empty())
    {
        int len = q.size();

        int i;
        FOR(i, len)
        {
            Node *curr = q.front();
            q.pop();

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        depth++;
    }

    return depth - 1;
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

    cout << "Height of given tree is: " << findHeightQueue(root);

    return 0;
}