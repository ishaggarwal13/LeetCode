class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        ios::sync_with_stdio(false);
        int dp[n];
        dp[0] = 0;

        vector<vector<int>> from(n);

        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] + 1;
            from[i].push_back(i - 1);
        }

        vector<int> ans(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];

            from[b].push_back(a);

            int change = dp[b];

            for (int k = b; k < n; k++) {
                for (int r : from[k]) {
                    dp[k] = min(dp[k], dp[r] + 1);
                }
                if (k == b)
                    if (dp[b] == change)
                        break;
            }
            ans[i] = dp[n - 1];
        }
        return ans;
    }
};