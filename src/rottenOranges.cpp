#include "rottenOranges.hpp"
#include <queue>

using namespace std;

int rottenOrange(vector<vector<int>> oranges)
{
    int rowCount = oranges.size();
    int colCount = oranges[0].size();

    queue<Cell> q;

    int rottingTime = 0;
    int fresh = 0;

    for (int row = 0; row < rowCount; row++)
    {
        for (int col = 0; col < colCount; col += 1)
        {
            if (oranges[row][col] == 2)
            {
                q.push({row, col, 0});
            }
            else if (oranges[row][col] == 1)
                fresh += 1;
        }
    }

    vector<int> rotRow = {-1, 0, 1, 0};
    vector<int> rotCol = {0, -1, 0, 1};

    while (!q.empty())
    {
        Cell loc = q.front();
        q.pop();

        rottingTime = max(rottingTime, loc.time);

        for (int i = 0; i < 4; i++)
        {
            int newRow = loc.row + rotRow[i];
            int newCol = loc.col + rotCol[i];

            if (newRow < 0 || newCol < 0 || newRow >= rowCount || newCol >= colCount)
                continue;

            if (oranges[newRow][newCol] == 1)
            {
                oranges[newRow][newCol] = 2;
                fresh -= 1;
                q.push({newRow, newCol, loc.time + 1});
            }
        }
    }

    return fresh ? -1 : rottingTime;
}