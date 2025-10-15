#include <iostream>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>> graph)
{
    queue<int> q;
    vector<int> colors(graph.size(), -1);

    for (int i = 0; i < graph.size(); i++)
    {
        if (colors[i] != -1)
            continue;

        q.push(i);
        colors[i] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int n : graph[node])
            {
                if (colors[n] == -1)
                {
                    colors[n] = !colors[node];
                    q.push(n);
                }
                else
                {
                    if (colors[n] == colors[node])
                        return false;
                }
            }
        }
    }

    return true;
}