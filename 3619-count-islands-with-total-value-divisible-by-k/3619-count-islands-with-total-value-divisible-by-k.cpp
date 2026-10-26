class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(grid[i][j] == 0) continue;

                queue<pair<int, int>> q;
                long long total = grid[i][j];
                q.push({i, j});
                grid[i][j] = 0;

                while(!q.empty()){
                    auto [r, c] = q.front();
                    q.pop();

                    for(int d=0; d<4; d++){
                        int nr = r + dr[d];
                        int nc = c + dc[d];

                        if(nc>=0 && nr>=0 && nc<m && nr<n && grid[nr][nc] != 0){
                            total += grid[nr][nc];
                            grid[nr][nc] = 0;
                            q.push({nr, nc});
                        }
                    }
                }
                
                if(total % k == 0){
                    count++;
                }
            }
        }
        return count;
    }
};