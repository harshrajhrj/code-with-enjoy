#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int _val)
    {
        val = _val;
        next = NULL;
    }
};

Node *mergeKnodes(vector<Node *> &lists)
{
    // Define custom comparator for min-heap (priority queue)
    // Returns true if a's value is greater than b's value (for min-heap behavior)
    auto compare = [](Node *a, Node *b)
    {
        return a->val > b->val;
    };

    priority_queue<Node *, vector<Node *>, decltype(compare)> pq(compare);

    for (auto node : lists)
    {
        if (node != nullptr)
        {
            pq.push(node);
        }
    }

    Node *dummyhead = new Node(0);
    Node *curr = dummyhead;

    while (!pq.empty())
    {
        auto minnode = pq.top();
        pq.pop();
        curr->next = minnode;
        curr = curr->next;

        if (minnode->next)
            pq.push(minnode->next);
    }

    return dummyhead->next;
}

int main()
{
    return 0;
}