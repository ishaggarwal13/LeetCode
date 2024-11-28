class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        deque<pair<int, int>> dq;
        dq.push_front({0,0});

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = 0;

        vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while(!dq.empty()){
            auto [x,y] = dq.front();
            dq.pop_front();

            for(auto [dx,dy] : directions){
                int newx = x+dx;
                int newy = y+dy;

                if(newx >=0 && newx < m && newy >= 0 && newy < n){
                    int newdist = dp[x][y] + grid[newx][newy];
                    if(newdist < dp[newx][newy]){
                        dp[newx][newy] = newdist;
                        if (grid[newx][newy] == 0) {
                            dq.push_front({newx, newy});
                        } else {
                            dq.push_back({newx, newy});
                        }
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};