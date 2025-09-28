#pragma once

#include <unordered_map>
#include <vector>

struct pair_hash
{
    size_t operator()(const std::pair<int, int> &p) const
    {
        // A common trick: mix the two ints into one hash
        return ((size_t)p.first << 32) ^ (size_t)p.second;
    }
};

int countDistinctIslands(std::vector<std::vector<int>> &grid);
