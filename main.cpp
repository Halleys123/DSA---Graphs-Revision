#include <vector>
#include <unordered_map>
#include <queue>
#include <stdio.h>

#include "bfs.hpp"
#include "dfs.hpp"
#include "provinces.hpp"
#include "islands.hpp"
#include "floodFill.hpp"

using namespace std;

int main()
{
    printf("\x1b[0m\nProgram started...\n");

    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}};
    printf("Number of islands = %d", islandCount(grid));

    vector<vector<int>> image = {
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 1}};

    floodFill(image, {1, 2}, 2);
    printf("\n");

    for (auto i : image)
    {
        for (auto j : i)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
    printf("\n");

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