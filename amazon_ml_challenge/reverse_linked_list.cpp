#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *l1)
{
    if (l1 || l1->next == nullptr)
        return l1;

    ListNode *head = reverseList(l1->next);
    l1->next->next = l1;
    l1->next = nullptr;
    return head;
}

ListNode *iterative(ListNode *l1)
{
    ListNode *prev = nullptr;
    ListNode *curr = l1;
    while (curr != nullptr)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}
int main()
{
    return 0;
}