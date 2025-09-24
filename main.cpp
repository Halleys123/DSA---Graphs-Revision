#include <vector>
#include <unordered_map>
#include <queue>
#include <stdio.h>

#include "bfs.hpp"
#include "dfs.hpp"
#include "provinces.hpp"

using namespace std;

int main()
{
    printf("\x1b[0m\nProgram started...\n");

    int nodes, edges;
    int isDirected = 0;

    unordered_map<int, vector<int>> graph;

    scanf("%d %d", &nodes, &edges);

    int u, v;
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        if (!isDirected)
        {
            graph[v].push_back(u);
        }
        printf("\n");
    }
    BFS(graph);
    printf("\n");
    DFS(graph);
    printf("\n");
    int provinces = CountProvinces(graph);
    printf("\nGraph has %d provinces\n", provinces);

    printf("\x1b[0m");
    return 0;
}