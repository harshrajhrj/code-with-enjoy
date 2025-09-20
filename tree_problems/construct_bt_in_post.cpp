// https://www.geeksforgeeks.org/dsa/construct-a-binary-tree-from-postorder-and-inorder/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::pair;
using std::unordered_map;
using std::vector;

#define FOR(x, to) for (x = 0; x < (to); x++)
#define FORI(x, to) for (x; x < (to); x++)
#define FORR(x, arr) for (auto &x : arr)
#define ALL(a) (a.begin(), a.end())
#define mem(a, n) memset(a, n, sizeof(a))

typedef vector<int> vi;

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

Node *constructBT_util(vi &in, vi &post, int inStart, int inEnd, int &postEnd, unordered_map<int, int> mp)
{
    if (inStart > inEnd)
        return nullptr;

    int rootVal = post[postEnd--];
    Node *root = new Node(rootVal);
    int rootIdx = mp[rootVal];

    root->right = constructBT_util(in, post, rootIdx + 1, inEnd, postEnd, mp);
    root->left = constructBT_util(in, post, inStart, rootIdx - 1, postEnd, mp);

    return root;
}
Node *constructBT(vi &in, vi &post)
{
    unordered_map<int, int> mp;
    int i;
    FOR(i, in.size())
    {
        mp[in[i]] = i;
    }

    int postEnd = post.size() - 1;
    return constructBT_util(in, post, 0, in.size() - 1, postEnd, mp);
}

void print_tree_preorder(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    print_tree_preorder(root->left);
    print_tree_preorder(root->right);
}

int main()
{
    vi inorder = {4, 8, 2, 5, 1, 6, 3, 7};
    vi postorder = {8, 4, 5, 2, 6, 7, 3, 1};

    Node *root = constructBT(inorder, postorder);

    print_tree_preorder(root);

    return 0;
}