class Solution {
public:
    // using BFS using queue as DS
    // O(n x m) TC and O(n x m) SC
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        // directions for up down left and right (dr, dc)
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(grid[i][j] != 0) continue;

                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = 1; //mark as visited
                bool closed = true;

                while(!q.empty()){
                    auto [r, c] = q.front();
                    q.pop();

                    // condition - for outer
                    if(r == 0 || c == 0 || r == n-1 || c == m-1){
                        closed = false;
                    }

                    for(int d = 0; d<4; d++){
                        int nr = r + dr[d];
                        int nc = c + dc[d];

                        if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc] == 0){
                            grid[nr][nc] = 1;
                            q.push({nr, nc});
                        }
                    }
                }

                if(closed) count++;
            }
        }
        
        return count;
    }
};