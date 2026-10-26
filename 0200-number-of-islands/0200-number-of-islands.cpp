class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        // Up, down, left, right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (grid[i][j] == '0') continue;

                count++;

                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = '0';

                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int nr = r + dr[d];
                        int nc = c + dc[d];

                        if (nr >= 0 && nc >= 0 &&
                            nr < n && nc < m &&
                            grid[nr][nc] == '1') {

                            grid[nr][nc] = '0';
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
        return count;
    }
};