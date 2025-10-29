#include "kahns.hpp"
#include <queue>

using namespace std;

vector<int> kahns(unordered_map<int, vector<int>> &graph)
{
    vector<int> inDegree(graph.size() + 1, 0);
    vector<int> topo;
    queue<int> q;

    for (auto &i : graph)
    {
        for (int node : i.second)
        {
            inDegree[node] += 1;
        }
    }

    for (int i = 0; i < inDegree.size(); i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        printf("%d ", node);

        for (auto i : graph[node])
        {
            inDegree[i] -= 1;
            if (inDegree[i] == 0)
                q.push(i);
        }
    }

    return topo;
}