/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0, fresh = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) ++fresh;
            }
        while (!q.empty() && fresh) {
            ++res;
            for (int k = q.size(); k > 0; --k) {
                auto t = q.front(); q.pop();
                for (auto dir : dirs) {
                    int x = t.first + dir[0], y = t.second + dir[1];
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push({x, y});
                        --fresh;
                    }
                }
            }
        }
        return fresh ? -1 : res;
    }
};
// @lc code=end

