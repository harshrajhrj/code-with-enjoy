#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::max;
using std::queue;
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

Node *findTarget(Node *root, int target)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node->data == target)
            return node;

        if (node->left)
            q.push(node->left);

        if (node->right)
            q.push(node->right);
    }

    return nullptr;
}

void identifyParents(unordered_map<Node *, Node *> &mp, Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node->left)
        {
            mp[node->left] = node;
            q.push(node->left);
        }

        if (node->right)
        {
            mp[node->right] = node;
            q.push(node->right);
        }
    }
}

vi solve(Node *root, int target, int k)
{
    unordered_map<Node *, Node *> mp;
    identifyParents(mp, root);

    Node *targetNode = findTarget(root, target);

    unordered_map<Node *, bool> visited;
    queue<Node *> q;
    q.push(targetNode);
    visited[targetNode] = true;

    int level = 0;

    while (!q.empty())
    {
        if (level++ == k)
            break;
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++)
        {
            Node *node = q.front();
            q.pop();

            if (node->left && !visited[node->left])
            {
                q.push(node->left);
                visited[node->left] = true;
            }
            if (node->right && !visited[node->right])
            {
                q.push(node->right);
                visited[node->right] = true;
            }
            if (mp[node] && !visited[mp[node]])
            {
                q.push(mp[node]);
                visited[mp[node]] = true;
            }
        }
    }

    vi ans;
    while (!q.empty())
    {
        ans.push_back(q.front()->data);
        q.pop();
    }

    return ans;
}

void printList(vi arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    // Create a hard coded tree.
    //         20
    //       /    \
    //      7      24
    //    /   \
    //   4     3
    //        /
    //       1
    Node *root = new Node(20);
    root->left = new Node(7);
    root->right = new Node(24);
    root->left->left = new Node(4);
    root->left->right = new Node(3);
    root->left->right->left = new Node(1);

    int target = 7, k = 2;
    vector<int> ans = solve(root, target, k);

    printList(ans);
    return 0;
}