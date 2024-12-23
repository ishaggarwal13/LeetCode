const int MAX_N = 3e4+5;
vector<int> adj[MAX_N];
bool visited[MAX_N];

class Solution {
    int ans = 0;

    void prune(int n) {
        for (int i = 0; i < n; ++i) adj[i].clear();
    }

    void buildGraph(vector<vector<int>>& edges) {
        for (const auto &edge: edges) 
            adj[edge[0]].emplace_back(edge[1]),
            adj[edge[1]].emplace_back(edge[0]);
    }

    long long dfs(int node, int parent, vector<int>& values, int k) {
        long long sum = values[node];
        for (const int &neighbor: adj[node]) {
            if (neighbor == parent) continue;
            sum += dfs(neighbor, node, values, k);
            sum %= k;
        }
        const bool sum_divisible_by_k = sum % k == 0;
        ans += sum_divisible_by_k;
        return sum_divisible_by_k ? 0 : sum;
    }
    
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        prune(n);
        buildGraph(edges);
        
        dfs(0, -1, values, k);
        return ans;
    }
};