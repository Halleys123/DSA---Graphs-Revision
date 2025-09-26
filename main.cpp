#include <vector>
#include <unordered_map>
#include <queue>
#include <stdio.h>

#include "bfs.hpp"
#include "dfs.hpp"
#include "provinces.hpp"
#include "islands.hpp"
#include "floodFill.hpp"
#include "cycleDetection.hpp"

using namespace std;

vector<unordered_map<int, vector<int>>> graphList = {
    // Graph 1: Cycle (1-2-3-1)
    {
        {1, {2, 3}},
        {2, {3, 1}},
        {3, {1, 2}}},
    // Graph 2: No cycle (1-2-3)
    {
        {1, {2}},
        {2, {3, 1}},
        {3, {2}}},
    // Graph 3: Cycle (4-5-6-4)
    {
        {4, {5}},
        {5, {6}},
        {6, {4}}},
    // Graph 4: No cycle (7-8, 8-9)
    {
        {7, {8}},
        {8, {9}},
        {9, {}}},
    // Graph 5: Cycle (10-11-12-10), plus an isolated node 13
    {
        {10, {11}},
        {11, {12}},
        {12, {10}},
        {13, {}}}

    ,
    // Graph 6
    {
        {1, {2, 3}}, // Node 1
        {2, {4}},    // Node 2
        {3, {5}},    // Node 3
        {4, {6}}     // Node 4
        // Node 5
    }
    // End
};

int main()
{
    printf("\x1b[0m\nProgram started...\n");

    for (int i = 0; i < graphList.size(); i++)
    {
        printf("Graph %d %s a cycle\n", i + 1, graphHasCycle(graphList[i]) ? "has" : "don't");
    }
    printf("\n");

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