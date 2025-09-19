#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::lower_bound;
using std::max;
using std::pair;
using std::queue;
using std::stack;
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

void printArrInOrder(Node *node)
{
    if (node == nullptr)
        return;

    printArrInOrder(node->left);
    cout << node->data << " ";
    printArrInOrder(node->right);
}

//=====NAIVE=====
Node *insertBST_1(Node *node, int key);
Node *constructBST_1(vi &pre)
{
    Node *root = nullptr;
    for (int key : pre)
    {
        root = insertBST_1(root, key);
    }
    return root;
}

Node *insertBST_1(Node *node, int val)
{
    if (node == nullptr)
        return new Node(val);

    if (node->data < val)
        node->right = insertBST_1(node->right, val);
    else if (node->data > val)
        node->left = insertBST_1(node->left, val);

    return node;
}

//=====BETTER=====
Node *insertBST_2(vi &pre, int low, int high);

Node *constructBST_2(vi &pre)
{
    return insertBST_2(pre, 0, pre.size() - 1);
}

Node *insertBST_2(vi &arr, int low, int high)
{
    if (low > high)
        return nullptr;

    Node *root = new Node(arr[low]);

    if (low == high)
        return root;

    int i = low + 1;
    FORI(i, arr.size())
    {
        if (arr[i] > arr[low])
            break;
    }

    root->left = insertBST_2(arr, low + 1, i - 1);
    root->right = insertBST_2(arr, i, high);

    return root;
}

//=====EFFICIENT=====
Node *insertBST_3(vi &pre, int &idx, int min, int max);
Node *constructBST_3(vi &pre)
{
    int idx = 0;
    return insertBST_3(pre, idx, INT_MIN, INT_MAX);
}

Node *insertBST_3(vi &pre, int &idx, int min, int max)
{
    if (idx >= pre.size())
        return nullptr;

    int val = pre[idx];

    if (val <= min || val >= max)
        return nullptr;

    Node *node = new Node(val);
    idx++;

    if (idx < pre.size())
        node->left = insertBST_3(pre, idx, min, val);
    if (idx < pre.size())
        node->right = insertBST_3(pre, idx, val, max);

    return node;
}

int main()
{
    vector<int> pre = {10, 5, 1, 7, 40, 50};
    // Node *root = constructBST_1(pre); // NAIVE TC - O(N^2)
    // Node *root = constructBST_2(pre); // BETTER - O(N^2)
    Node *root = constructBST_3(pre); // EFFICIENT - O(N)
    printArrInOrder(root);
    return 0;
}
