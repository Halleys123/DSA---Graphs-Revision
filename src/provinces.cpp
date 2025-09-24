#include "provinces.hpp"

#include <queue>
#include <unordered_map>

using namespace std;

int isLeft(std::unordered_map<int, bool> &visisted)
{
    for (auto i : visisted)
    {
        if (i.second == false)
        {
            return i.first;
        }
    }

    return -1;
}

int CountProvinces(std::unordered_map<int, std::vector<int>> &graph)
{
    unordered_map<int, bool> visited;

    for (const auto &pair : graph)
    {
        visited[pair.first] = false;
    }

    queue<int> q;
    q.push(graph.begin()->first);

    visited[q.front()] = true;

    int proviceCount = 0;
    int isLeftCount = isLeft(visited);

    while (isLeftCount != -1)
    {
        proviceCount += 1;
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

        isLeftCount = isLeft(visited);
        if (isLeftCount != -1)
        {
            q.push(isLeftCount);
            visited[isLeftCount] = true;
        }
    }

    return proviceCount;
}
