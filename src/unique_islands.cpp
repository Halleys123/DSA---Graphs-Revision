#include <queue>
#include <set>
#include <algorithm>
#include "unique_islands.hpp"

using namespace std;

// This is not working.

int countDistinctIslands(vector<vector<int>> &grid)
{
    set<vector<pair<int, int>>> uniqueIslands;
    queue<pair<int, int>> q;

    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, -1, 0, 1};

    for (int row = 0; row < grid.size(); row += 1)
    {
        for (int col = 0; col < grid[0].size(); col += 1)
        {

            int x = 0;
            int y = 0;

            if (!grid[row][col])
                continue;
            q.push({row, col});
            grid[row][col] = 0;
            vector<pair<int, int>> shape;

            while (!q.empty())
            {
                pair<int, int> node = q.front();
                q.pop();
                shape.push_back({row - node.first, col - node.second});

                for (int i = 0; i < 4; i++)
                {
                    int newRow = node.first + dRow[i];
                    int newCol = node.second + dCol[i];

                    if (newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid[0].size())
                        continue;
                    if (!grid[newRow][newCol])
                        continue;

                    grid[newRow][newCol] = 0;
                    q.push({newRow, newCol});

                    if (dRow[i])
                        x += dRow[i];
                    else
                        y += dCol[i];
                }
            }

            sort(shape.begin(), shape.end());
            uniqueIslands.insert(shape);
        }
    }

    return uniqueIslands.size();
}
