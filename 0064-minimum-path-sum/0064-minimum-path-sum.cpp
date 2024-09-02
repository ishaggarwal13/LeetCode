class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(n == 1 && m == 1) return grid[0][0];

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0][0] = grid[0][0];

        vector<pair<int,int>> directions = {{0, 1}, {1, 0}};

        priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>,
                    greater<pair<int, pair<int,int>>>> pq;
        pq.push({grid[0][0], {0,0}});

        while(!pq.empty()){
            int currsum = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == n - 1 && y == m - 1) return currsum;

            for(auto& dir : directions){
                int newx = x + dir.first;
                int newy = y + dir.second;
                
                if(newx >= 0 && newx < n && newy >= 0 && newy < m){
                    int pathsum = currsum + grid[newx][newy];

                    if(pathsum < dp[newx][newy]){
                        dp[newx][newy] = pathsum;
                        pq.push({pathsum, {newx, newy}});
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};