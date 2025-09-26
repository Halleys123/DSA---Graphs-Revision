#include "cycleDetection.hpp"
#include <stack>
#include <queue>

using namespace std;

bool graphHasCycle(unordered_map<int, vector<int>> &graph)
{
    unordered_map<int, bool> visited;
    stack<int> s;

    for (auto i : graph)
    {
        visited[i.first] = false;
    }

    for (auto &i : graph)
    {
        if (visited[i.first])
            continue;

        s.push(i.first);

        while (!s.empty())
        {
            int node = s.top();
            s.pop();

            for (int n : graph[node])
            {
                if (visited[n])
                    return true;

                visited[node] = true;
                s.push(n);
            }
        }
    }

    return false;
}
// bool graphHasCycle(unordered_map<int, vector<int>> &graph)
// {
//     unordered_map<int, bool> visited;
//     queue<pair<int, int>> q;

//     for (auto i : graph)
//     {
//         visited[i.first] = false;
//     }

//     for (auto &i : graph)
//     {
//         if (visited[i.first])
//             continue;

//         q.push({i.first, -1});

//         while (!q.empty())
//         {
//             pair<int, int> node = q.front();
//             q.pop();

//             for (int n : graph[node.first])
//             {
//                 if (!visited[n])
//                 {
//                     visited[node.first] = true;
//                     q.push({n, node.first});
//                 }
//                 else if (n != node.second)
//                     return true;
//             }
//         }
//     }

//     return false;
// }