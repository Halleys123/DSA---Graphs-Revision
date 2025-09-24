#include <unordered_map>
#include <queue>

#include "islands.hpp"

using namespace std;

int islandCount(const vector<vector<int>> &grid)
{

    int gridCols = grid.size();
    int gridRows = grid[0].size();

    vector<vector<bool>> visited(gridCols, vector<bool>(gridRows, false));

    vector<int> xdir = {-1, 0, 1, 0};
    vector<int> ydir = {0, -1, 0, 1};
    int islands = 0;

    for (int row = 0; row < gridCols; row++)
    {
        for (int col = 0; col < gridRows; col++)
        {

            if (grid[row][col] == 0 || visited[row][col])
                continue;

            queue<pair<int, int>> q;
            visited[row][col] = true;
            q.push({row, col});
            islands += 1;

            while (!q.empty())
            {
                pair<int, int> node = q.front();
                q.pop();

                for (int i = 0; i < 4; i += 1)
                {
                    int nx = xdir[i] + node.first;
                    int ny = ydir[i] + node.second;

                    if (nx < 0 || nx >= gridCols || ny < 0 || ny >= gridRows)
                        continue;

                    if (visited[nx][ny] || grid[nx][ny] == 0)
                        continue;

                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    return islands;
}