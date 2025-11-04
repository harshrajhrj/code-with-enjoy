#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
private:
    struct Node
    {
        int key;
        int value;
        Node *prev;
        Node *next;

        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int currentSize;
    int maxCapacity;
    Node *dummyhead;
    Node *dummytail;
    unordered_map<int, Node *> keytonode;

    void removeNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(Node *node)
    {
        node->next = dummyhead->next;
        node->prev = dummyhead;
        dummyhead->next->prev = node;
        dummyhead->next = node;
    }

public:
    LRUCache(int capacity) : currentSize(0), maxCapacity(capacity)
    {
        dummyhead = new Node(0, 0);
        dummytail = new Node(0, 0);
        dummyhead->next = dummytail;
        dummytail->prev = dummyhead;
    }

    int get(int key)
    {
        if (keytonode.find(key) == keytonode.end())
            return -1;

        Node *node = keytonode[key];
        removeNode(node);
        addToHead(node);

        return node->value;
    }

    void put(int key, int value)
    {
        if (keytonode.find(key) != keytonode.end())
        {
            Node *node = keytonode[key];
            removeNode(node);
            addToHead(node);
            node->value = value;
        }
        else
        {
            Node *newnode = new Node(key, value);
            keytonode[key] = newnode;
            addToHead(newnode);
            currentSize++;

            if (currentSize > maxCapacity)
            {
                Node *leastNode = dummytail->prev; // if prev node is removed then where dummytail->prev would point
                keytonode.erase(leastNode->key);
                removeNode(leastNode);
                delete leastNode;
                currentSize--;
            }
        }
    }
};