/**
 * @file 02 topological_sort.cpp
 * https://www.geeksforgeeks.org/dsa/topological-sorting/
 * https://www.geeksforgeeks.org/problems/topological-sort/1
 */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createAdjList(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    for(auto it : edges) {
        adj[it[0]].push_back(it[1]);
    }
    return adj;
}

void topological_sort_util(int v, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st)
{
    visited[v]= true;
    for(auto it: adj[v])
    {
        if(!visited[it])
            topological_sort_util(it, adj, visited, st);
    }
    st.push(v);
}

vector<int> topological_sort(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj = createAdjList(V, edges);
    stack<int> st;
    vector<bool> visited(V, false);

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
            topological_sort_util(i, adj, visited, st);
    }

    vector<int> ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main() {
    int V = 6;
    vector<vector<int>> edges = {
        {2, 3},
        {3, 1},
        {4, 0},
        {4, 1},
        {5, 0},
        {5, 2}
    };

    vector<int> ans = topological_sort(V, edges);

    for(auto node: ans) {
        cout<< node << " ";
    }
    cout<<endl;

    return 0;
}