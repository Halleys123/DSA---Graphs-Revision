#include <unordered_map>
#include <queue>

using namespace std;

bool graphHasCycle(unordered_map<int, vector<int>> &graph)
{
    unordered_map<int, bool> visited;
    queue<pair<int, int>> q;

    for (auto i : graph)
    {
        visited[i.first] = false;
    }

    for (auto &i : graph)
    {
        if (visited[i.first])
            continue;

        q.push({i.first, -1});

        while (!q.empty())
        {
            pair<int, int> node = q.front();
            q.pop();
            visited[node.first] = true;

            for (int n : graph[node.first])
            {
                if (n != node.second && visited[n])
                    return true;

                q.push({n, node.first});
            }
        }
    }

    return false;
}