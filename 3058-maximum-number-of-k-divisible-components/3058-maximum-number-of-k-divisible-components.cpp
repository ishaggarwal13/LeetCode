class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            adj[i].reserve(7);
        }
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        auto dfs = [&](auto&& self, int v, int p = -1) -> int {
            int sm = 0;
            for (int u : adj[v]) {
                if (u != p) {
                    sm += self(self, u, v);
                    sm %= k;
                }
            }
            if ((sm + values[v]) % k == 0) {
                ++ans;
            }
            return sm + values[v];
        };
        dfs(dfs, 0);
        return ans;
    }
};