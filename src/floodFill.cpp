#include "floodFill.hpp"
#include <queue>

using namespace std;

void floodFill(vector<vector<int>> &image, pair<int, int> position, int newColor)
{
    int rowsCount = image.size();
    int colsCount = image[0].size();

    int row = position.first;
    int col = position.second;

    vector<vector<bool>> visited(rowsCount, vector<bool>(colsCount, false));
    queue<pair<int, int>> q;

    int color = image[row][col];

    q.push(position);
    visited[row][col] = true;
    image[row][col] = newColor;

    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();

        for (int r = -1; r <= 1; r += 1)
        {
            for (int c = -1; c <= 1; c += 1)
            {
                int newRow = node.first + r;
                int newCol = node.second + c;

                if (newRow < 0 || newCol < 0 || newRow >= rowsCount || newCol >= colsCount)
                    continue;

                if (!visited[newRow][newCol] && image[newRow][newCol] == color)
                {
                    image[newRow][newCol] = newColor;
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
    }
}