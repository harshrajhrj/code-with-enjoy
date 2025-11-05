#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copylist(Node *head)
{
    Node *dummyhead = new Node(0);
    Node *curr = dummyhead;
    Node *currentOriginal = head;
    unordered_map<Node *, Node *> mp;

    while (currentOriginal)
    {
        Node *newnode = new Node(currentOriginal->val);
        // we need a dummy node to connect next pointers
        curr->next = newnode;
        curr = newnode;
        mp[currentOriginal] = newnode;

        currentOriginal = currentOriginal->next;
    }

    currentOriginal = head;

    while (currentOriginal)
    {
        Node *copiedNode = mp[currentOriginal];
        if (currentOriginal->random)
        {
            Node *randomnode = mp[currentOriginal->random];
            copiedNode->random = randomnode;
        }
        else
        {
            copiedNode->random = nullptr;
        }

        currentOriginal = currentOriginal->next;
    }

    return dummyhead->next;
}

int main()
{
    return 0;
}