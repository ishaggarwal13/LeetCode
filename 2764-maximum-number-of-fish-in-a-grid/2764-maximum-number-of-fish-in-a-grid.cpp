class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish=0;
        int row = grid.size();
        int col = grid[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] > 0){
                    int total = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while(!q.empty()){
                        auto[r,c] = q.front();
                        q.pop();
                        if(grid[r][c] == 0) continue;
                        total += grid[r][c];
                        grid[r][c] = 0;

                        int dir[] = {1, 0, -1, 0, 1};
                        for(int k=0; k<4; k++){
                            int nr = r + dir[k];
                            int nc = c + dir[k+1];

                            if(nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc]>0){
                                q.push({nr, nc});
                            }
                        }
                    }
                    maxFish = max(maxFish, total);
                }
            }
        }
        return maxFish;
    }
};