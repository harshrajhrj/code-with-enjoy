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

Node *addtwonumbers(Node * l1, Node*l2)
{
    Node *dummyhead = new Node(0);
    Node *curr = dummyhead;

    int carry=0;
    while(l1 || l2 || carry != 0)
    {
        int a = l1 ? l1->val : 0;
        int b = l2 ? l2->val : 0;

        int sum = carry + a + b;
        carry = sum / 10;
        Node *newnode = new Node(sum % 10);
        curr->next = newnode;
        curr = curr->next;

        // edge case if only carry is left and both nodes have been traversed
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    }

    return dummyhead->next;
}

int main()
{

}