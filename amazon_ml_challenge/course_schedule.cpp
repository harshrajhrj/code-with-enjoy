#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, vector<int> &visited, vector<int> &visitedPath, vector<int> &courseOrder, vector<vector<int>> &adj)
{
    visited[i] = 1;
    visitedPath[i] = 1;

    for (auto &neighbor : adj[i])
    {
        if (!visited[neighbor])
        {
            if (!dfs(neighbor, visited, visitedPath, courseOrder, adj))
                return false;
        }
        else if (visitedPath[neighbor])
            return false;
    }

    visitedPath[i] = 0;
    courseOrder.push_back(i);

    return true;
}
vector<int> canFinish(int courses, vector<vector<int>> &prerequisities)
{
    vector<vector<int>> adj(courses);
    for (auto &prerequisite : prerequisities)
    {
        int course = prerequisite[0];
        int prerequisiteCourse = prerequisite[1];

        adj[prerequisiteCourse].push_back(course);
    }

    vector<int> visited(courses, 0);
    vector<int> visitedPath(courses, 0);

    vector<int> courseOrder;

    for (int i = 0; i < courses; i++)
    {
        if (!visited[i])
        {
            if (!dfs(i, visited, visitedPath, courseOrder, adj))
                return {};
        }
    }

    return courseOrder;
}
int main()
{

    int courses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    vector<int> courseOrder = canFinish(courses, prerequisites);

    if (courseOrder.size())
    {
        reverse(courseOrder.begin(), courseOrder.end());
        for (int i = 0; i < courseOrder.size(); i++)
        {
            cout << courseOrder[i] << " ";
        }
    }
    else
    {
        cout << "Not possible";
    }

    return 0;
}