// https://www.geeksforgeeks.org/dsa/inorder-traversal-of-binary-tree/

// https://www.geeksforgeeks.org/dsa/inorder-tree-traversal-without-recursion-and-without-stack/ [Morris Traversal]

#include <bits/stdc++.h>

using std::cin;
using std::cout;
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

vi morris_traversal(Node *root)
{
    vi res;
    Node *curr = root;

    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            res.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            // finding inorder predecessor or curr
            Node *prev = curr->left;
            while (prev->right != nullptr && prev->right != curr)
                prev = prev->right;

            // making curr the right child of its inorder predecessor
            if (prev->right == nullptr)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = nullptr;
                res.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return res;
}
int main()
{
    // Representation of input binary tree:
    //           1
    //          / \
    //         2   3
    //        / \  
    //       4   5
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vi res = morris_traversal(root);
    for (auto &x : res)
    {
        cout << x << " ";
    }
    return 0;
}