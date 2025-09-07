// https://www.geeksforgeeks.org/postorder-traversal-of-binary-tree/
// https://www.geeksforgeeks.org/dsa/iterative-postorder-traversal/ (using two stacks)
// https://www.geeksforgeeks.org/dsa/iterative-postorder-traversal-using-stack/ (using one stack)
// https://www.geeksforgeeks.org/dsa/postorder-traversal-binary-tree-without-recursion-without-stack/
// https://www.geeksforgeeks.org/dsa/find-postorder-traversal-of-bst-from-preorder-traversal/
// https://www.geeksforgeeks.org/dsa/morris-traversal-for-postorder/
// https://www.geeksforgeeks.org/dsa/print-postorder-from-given-inorder-and-preorder-traversals/


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

