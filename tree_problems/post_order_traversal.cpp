// https://www.geeksforgeeks.org/postorder-traversal-of-binary-tree/
// https://www.geeksforgeeks.org/dsa/iterative-postorder-traversal/ (using two stacks)
// https://www.geeksforgeeks.org/dsa/iterative-postorder-traversal-using-stack/ (using one stack)
// https://www.geeksforgeeks.org/dsa/postorder-traversal-binary-tree-without-recursion-without-stack/
// https://www.geeksforgeeks.org/dsa/find-postorder-traversal-of-bst-from-preorder-traversal/
// https://www.geeksforgeeks.org/dsa/morris-traversal-for-postorder/
// https://www.geeksforgeeks.org/dsa/print-postorder-from-given-inorder-and-preorder-traversals/

// Other questions: https://www.geeksforgeeks.org/tag/morris-traversal/

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::max;
using std::pair;
using std::queue;
using std::reverse;
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

void solve(Node *root)
{
    if (root == nullptr)
        return;

    solve(root->left);
    solve(root->right);
    cout << root->data << " ";
}

void solve_using_two_stacks(Node *root)
{
    stack<Node *> s1;
    stack<Node *> s2;

    s1.push(root);

    while (!s1.empty())
    {
        Node *node = s1.top();
        s1.pop();
        s2.push(node);

        if (node->left)
            s1.push(node->left);

        if (node->right)
            s1.push(node->right);
    }

    while (!s2.empty())
    {
        Node *node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }
}

void solve_using_stack_v1(Node *root)
{
    stack<Node *> st;

    while (true)
    {
        while (root)
        {
            st.push(root);
            st.push(root);
            root = root->left;
        }

        if (st.empty())
            return;

        root = st.top();
        st.pop();

        if (!st.empty() && st.top() == root)
        {
            root = root->right;
        }
        else
        {
            cout << root->data << " ";
            root = nullptr;
        }
    }
}

void solve_using_stack_v2(Node *root)
{
    stack<pair<Node *, int>> st;

    st.push({root, 0});

    while (!st.empty())
    {
        pair<Node *, int> node = st.top();
        // st.pop();

        if (node.second == 0)
        {
            st.top().second = 1;
            if (node.first->left)
                st.push({node.first->left, 0});
        }
        else if (node.second == 1)
        {
            st.top().second = 2;
            if (node.first->right)
                st.push({node.first->right, 0});
        }
        else
        {
            cout << node.first->data << " ";
            st.pop();
        }
    }
}

void solve_using_bst_preorder_util(vi &arr, int &idx, int min, int max)
{
    if (idx >= arr.size())
        return;

    int val = arr[idx];

    if (val < min || val > max)
        return;

    idx++;

    solve_using_bst_preorder_util(arr, idx, min, val);
    solve_using_bst_preorder_util(arr, idx, val, max);

    cout << val << " ";
}
void solve_using_bst_preorder(vi &arr)
{
    int idx = 0;
    solve_using_bst_preorder_util(arr, idx, INT_MIN, INT_MAX);
}

void solve_using_morris_traversal(Node *root)
{
    vi res;
    Node *curr = root;

    while (curr != nullptr)
    {
        if (curr->right == nullptr)
        {
            res.push_back(curr->data);
            curr = curr->left;
        }
        else
        {
            Node *prev = curr->right;
            while (prev->left != nullptr && prev->left != curr)
                prev = prev->left;

            if (prev->left == nullptr)
            {
                res.push_back(curr->data);
                prev->left = curr;
                curr = curr->right;
            }
            else
            {
                prev->left = nullptr;
                curr = curr->left;
            }
        }
    }

    reverse(res.begin(), res.end());

    for (auto &x : res)
    {
        cout << x << " ";
    }
}
//==================================================================//
// Print postorder traversal from given inorder and preorder traversal
// Naive approach : O(N^2) <- TC

int search(vi &in, int root)
{
    int i;
    FOR(i, in.size())
    {
        if (in[i] == root)
            return i;
    }
    return -1;
}

void solve_using_inorder_preorder_util_1(vi &in, vi &pre, int inStart, int inEnd, int preStart)
{
    if (inStart > inEnd)
        return;

    int root_idx = search(in, pre[preStart]);

    if (root_idx > inStart) // this means we have some nodes in left subtree
        solve_using_inorder_preorder_util_1(in, pre, inStart, root_idx - 1, preStart + 1);

    if (root_idx < inEnd)
        solve_using_inorder_preorder_util_1(in, pre, root_idx + 1, inEnd, preStart + root_idx - inStart + 1);

    cout << pre[preStart] << " ";
}

// Efficient approach - O(N) <- TC

void solve_using_inorder_preorder_util_2(vi &in, vi &pre, unordered_map<int, int> &mp, int inStart, int inEnd, int &preStart)
{
    if (inStart > inEnd)
        return;

    int rootIdx = mp[pre[preStart++]];
    // if (rootIdx > inStart)
    solve_using_inorder_preorder_util_2(in, pre, mp, inStart, rootIdx - 1, preStart);
    // if (rootIdx < inEnd)
    solve_using_inorder_preorder_util_2(in, pre, mp, rootIdx + 1, inEnd, preStart);

    cout << in[rootIdx] << " ";
}

void solve_using_inorder_preorder(vi &in, vi &pre)
{
    // naive
    // solve_using_inorder_preorder_util_1(in, pre, 0, in.size() - 1, 0);

    // efficient
    unordered_map<int, int> mp;
    int preStart = 0;

    int i;
    FOR(i, in.size())
    {
        mp[in[i]] = i;
    }
    solve_using_inorder_preorder_util_2(in, pre, mp, 0, in.size() - 1, preStart);
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

    // solve_using_stack_v2(root);

    // vi pre = {40, 30, 35, 80, 100};

    // solve_using_bst_preorder(pre);

    // solve_using_morris_traversal(root);

    vi in = {4, 2, 5, 1, 3, 6};
    vi pre = {1, 2, 4, 5, 3, 6};
    solve_using_inorder_preorder(in, pre);

    return 0;
}