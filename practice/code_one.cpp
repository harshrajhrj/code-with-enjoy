// Add element to the beginning of linked list
// Add element to the end of the linked list
#include <bits/stdc++.h>
using namespace std;

class LinkedList {
    public:
    int data;
    LinkedList *nextnode;
    LinkedList(int d)
    {
        data = d;
        nextnode = nullptr;
    }
    // void addEnd()
};


LinkedList* addBegin(LinkedList* head, int newData)
{
    LinkedList *newnode = new LinkedList(newData);
    newnode->nextnode = head;
    return newnode;
}

void print(LinkedList* head)
{
    if(head == nullptr)
        return;
    print(head->nextnode);
    cout << head->data << " ";
}

int main()
{
    LinkedList *head;
    head = addBegin(head, 5);
    head = addBegin(head, 10);
    head = addBegin(head, 15);
    head = addBegin(head, 25);
    head = addBegin(head, 1005);

    print(head->nextnode);
}