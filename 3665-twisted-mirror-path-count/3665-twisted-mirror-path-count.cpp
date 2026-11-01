
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int MOD = 1e9 + 7;

        // go[i][j][0] = landing cell when moving right
        // go[i][j][1] = landing cell when moving down
        // {-1, -1} means the move is invalid
        using Cell = pair<int, int>;

        vector<vector<array<Cell, 2>>> go(
            m, vector<array<Cell, 2>>(n)
        );

        // Step 1: Precompute landing cells
        // Work backwards because reflections only move right/down
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                for (int dir = 0; dir < 2; dir++) {

                    // 0 = right, 1 = down
                    int ni = i + (dir == 1);
                    int nj = j + (dir == 0);

                    if (ni >= m || nj >= n) {
                        go[i][j][dir] = {-1, -1};
                        continue;
                    }

                    // Empty cell: land directly
                    if (grid[ni][nj] == 0) {
                        go[i][j][dir] = {ni, nj};
                    }
                    else {
                        // Mirror: switch direction
                        go[i][j][dir] = go[ni][nj][1 - dir];
                    }
                }
            }
        }

        // Step 2: DP to count paths
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1 || dp[i][j] == 0)
                    continue;

                // Attempt both right and down
                for (int dir = 0; dir < 2; dir++) {

                    auto [x, y] = go[i][j][dir];

                    // Invalid move
                    if (x == -1)
                        continue;

                    dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
