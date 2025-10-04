#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

void dfs(int i, vi adjList[], vi &visited)
{
    visited[i] = 1;
    for (auto &neighbor : adjList[i])
        if (!visited[neighbor])
            dfs(neighbor, adjList, visited);
}

int solve(int V, vii &adjMatrix)
{
    vi adjList[V];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
        {
            if (adjMatrix[i][j] == 1 && i != j)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }

    vi visited(V, 0);
    int count = 0;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, adjList, visited);
            count++;
        }
    }

    return count;
}