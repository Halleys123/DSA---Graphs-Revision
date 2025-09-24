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

    int proviceCount = 0;

    for (const auto &pair : graph)
    {
        int start = pair.first;
        if (!visited[start])
        {
            q.push(start);
            visited[start] = true;

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
        }
    }

    return proviceCount;
}
