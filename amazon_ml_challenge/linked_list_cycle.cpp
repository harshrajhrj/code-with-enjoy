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

bool detectCycle(ListNode *head)
{
    ListNode *curr = head;
    unordered_set<ListNode *> visited;

    while (curr != nullptr)
    {
        if (visited.count(curr) > 0)
            return true;

        visited.insert(curr);
        curr = curr->next;
    }

    return false;
}