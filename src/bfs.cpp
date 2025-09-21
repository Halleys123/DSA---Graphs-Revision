#include "bfs.hpp"

#include <queue>
#include <unordered_map>

using namespace std;

void BFS(std::unordered_map<int, std::vector<int>> &graph)
{
    unordered_map<int, bool> visited;

    queue<int> q;
    q.push(graph.begin()->first);

    visited[q.front()] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        printf("%d ", node);

        for (int i : graph[node])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
