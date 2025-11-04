// https://www.geeksforgeeks.org/dsa/inorder-traversal-of-binary-tree/
// https://www.geeksforgeeks.org/dsa/inorder-tree-traversal-without-recursion/ [Iterative Traversal]
// https://www.geeksforgeeks.org/dsa/construct-tree-from-given-inorder-and-preorder-traversal/
// https://www.geeksforgeeks.org/dsa/inorder-tree-traversal-without-recursion-and-without-stack/ [Morris Traversal]

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::max;
using std::pair;
using std::queue;
using std::stack;
using std::unordered_map;
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

//==================================================================//
// Iterative traversal without using recursion [Naive]
void inorder_iterative_naive(Node *root)
{
    stack<Node *> st;

    Node *curr = root;

    while (curr != nullptr || !st.empty())
    {
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }

        // we have reached the nullptr
        curr = st.top();
        st.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}

// Inorder traversal without using recursion and stack [Efficient]
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

//==================================================================//
// Construct binary tree from given inorder and preorder traversal
Node *constructBT_util(vi &in, vi &pre, int inStart, int inEnd, int &preStart, unordered_map<int, int> mp)
{
    if (inStart > inEnd)
        return nullptr;

    int rootVal = pre[preStart++];
    Node *root = new Node(rootVal);
    int rootIdx = mp[rootVal];

    root->left = constructBT_util(in, pre, inStart, rootIdx - 1, preStart, mp);
    root->right = constructBT_util(in, pre, rootIdx + 1, inEnd, preStart, mp);

    return root;
}
Node *constructBT(vi &in, vi &pre)
{
    unordered_map<int, int> mp;
    int i;
    FOR(i, in.size())
    {
        mp[in[i]] = i;
    }
    int preStart = 0;
    return constructBT_util(in, pre, 0, in.size() - 1, preStart, mp);
}

void print_tree_inorder(Node *root)
{
    if (root == nullptr)
        return;

    print_tree_inorder(root->left);
    cout << root->data << " ";
    print_tree_inorder(root->right);
}

int main()
{
    // Representation of input binary tree:
    //           1
    //          / \
    //         2   3
    //        / \  
    //       4   5
    // Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);

    // inorder_iterative_naive(root);

    // vi res = morris_traversal(root);
    // for (auto &x : res)
    // {
    //     cout << x << " ";
    // }

    vi inorder = {3, 1, 4, 0, 5, 2};
    vi preorder = {0, 1, 3, 4, 2, 5};
    Node *root = constructBT(inorder, preorder);
    print_tree_inorder(root); // verify
    return 0;
}