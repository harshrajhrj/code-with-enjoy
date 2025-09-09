// https://www.geeksforgeeks.org/dsa/maximum-width-of-a-binary-tree/
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::max;
using std::queue;
using std::vector;

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
        return 0;

    int leftSubtree = findHeight(root->left);
    int rightSubtree = findHeight(root->left);

    return max(leftSubtree, rightSubtree) + 1;
}

int findWidth(Node *root, int level)
{
    if (root == nullptr)
        return 0;
    if (level == 1)
        return 1;

    return findWidth(root->left, level - 1) + findWidth(root->right, level - 1);
}

void solve_using_recursion(Node *root)
{
    int height = findHeight(root);

    int i = 1;
    int ans = INT_MIN;
    FORI(i, height + 1)
    {
        ans = max(ans, findWidth(root, i));
    }

    cout << ans;
}

void solve_using_queue(Node *root)
{
    queue<Node *> q;

    q.push(root);

    int ans = INT_MIN;

    while (!q.empty())
    {
        int n = q.size();
        ans = max(ans, n);

        int i = 0;
        FOR(i, n)
        {
            Node *root = q.front();
            q.pop();

            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
    }

    cout << ans;
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

    solve_using_queue(root);
}