#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        maxheap.push(num);
        minheap.push(maxheap.top());
        maxheap.pop();

        if (minheap.size() < maxheap.size() + 1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian()
    {
        return maxheap.size() == minheap.size() ? (maxheap.top() + minheap.top()) / 2 : minheap.top();
    }

private:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
};

int main()
{
    return 0;
}