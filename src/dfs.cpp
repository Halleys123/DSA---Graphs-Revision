#include "dfs.hpp"
#include <stack>

using namespace std;

void DFS(std::unordered_map<int, std::vector<int>> &graph)
{
    unordered_map<int, bool> visited;

    stack<int> s;
    s.push(graph.begin()->first);
    visited[s.top()] = true;

    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        printf("%d ", node);

        for (int i : graph[node])
        {
            if (!visited[i])
            {
                visited[i] = true;
                s.push(i);
            }
        }
    }
}