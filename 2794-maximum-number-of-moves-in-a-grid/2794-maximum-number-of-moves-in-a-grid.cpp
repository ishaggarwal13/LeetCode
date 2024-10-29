class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // 無法用 sentinel： 因為左邊界也需要和左邊的格子比較大小，但只有 dp 有多一列，grid 沒有
        // vector<int> dp(m + 2);    dp[0] = INT_MIN;    dp[m + 1] = INT_MIN;

        int res = 0;
        vector<int> dp(m);

        for (int j = 1; j < n; ++j) {
            int leftTop = 0;  // 1
            bool found = false;
            
            for (int i = 0; i < m; ++i) {
                int cur = -1;
                int nxtLeftTop = dp[i];  // next leftTop   1

                if (i - 1 >= 0 && leftTop != -1 && grid[i][j] > grid[i - 1][j - 1]) {
                    cur = max(cur, leftTop + 1);
                }
                if (dp[i] != -1 && grid[i][j] > grid[i][j - 1]) {
                    cur = max(cur, dp[i] + 1);
                }
                if (i + 1 < m && dp[i + 1] != -1 && grid[i][j] > grid[i + 1][j - 1]) {
                    cur = max(cur, dp[i + 1] + 1);
                }
                
                dp[i] = cur;
                found = found || (dp[i] != -1);  // check if found in this col
                
                leftTop = nxtLeftTop;
            }
            if (!found) break;
            res = j;
        }

        return res;
    }
};