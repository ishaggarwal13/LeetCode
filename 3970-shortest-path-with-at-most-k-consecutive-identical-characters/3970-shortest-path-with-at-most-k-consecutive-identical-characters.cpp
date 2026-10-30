class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Step 1: Create adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        // Step 2: Distance array
        // dist[node][count] = minimum distance
        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, INF)
        );

        // Step 3: Min heap
        // {distance, node, consecutive count}
        using State = tuple<long long, int, int>;

        priority_queue<State, vector<State>, greater<State>> pq;

        // Start from node 0
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        // Step 4: Dijkstra
        while (!pq.empty()) {

            auto [d, u, cnt] = pq.top();
            pq.pop();

            // Skip outdated states
            if (d != dist[u][cnt])
                continue;

            // Destination reached
            if (u == n - 1)
                return (int)d;

            // Explore neighbors
            for (auto [v, w] : adj[u]) {

                int nextCnt;

                if (labels[u] == labels[v]) {
                    nextCnt = cnt + 1;
                } else {
                    nextCnt = 1;
                }

                // Invalid consecutive count
                if (nextCnt > k)
                    continue;

                long long newDist = d + w;

                // Relax the edge
                if (newDist < dist[v][nextCnt]) {

                    dist[v][nextCnt] = newDist;

                    pq.push({newDist, v, nextCnt});
                }
            }
        }

        // No valid path exists
        return -1;
    }
};