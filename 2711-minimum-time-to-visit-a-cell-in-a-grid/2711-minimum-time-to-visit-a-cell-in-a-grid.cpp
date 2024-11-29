class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});

        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[0][0] = 1;

        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!pq.empty()) {
            auto node = pq.top();
            int time = node.first;
            int i = node.second.first;
            int j = node.second.second;

            pq.pop();
            if (i == m - 1 && j == n - 1) return time;

            for (auto it : dir) {
                int r = it.first + i;
                int c = it.second + j;

                if (r >= 0 && c >= 0 && r < m && c < n && !visited[r][c]) {
                    int extratime = ((grid[r][c] - time) % 2 == 0) ? 1 : 0;
                    int ntime = max(time + 1, grid[r][c] + extratime);
                    pq.push({ntime, {r, c}});
                    visited[r][c] = 1;
                }
            }
        }
        return -1;
    }
};