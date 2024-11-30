class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree, outDegree;

        // Build the graph and calculate in/out-degrees
        for (auto& pair : pairs) {
            int u = pair[0], v = pair[1];
            graph[u].push_back(v);
            outDegree[u]++;
            inDegree[v]++;
        }

        // Find the starting node (vertex with out-degree > in-degree)
        int startNode = pairs[0][0];
        for (auto& [node, _] : graph) {
            if (outDegree[node] > inDegree[node]) {
                startNode = node;
                break;
            }
        }

        // Hierholzer's algorithm for finding the Eulerian path
        stack<int> stk;
        deque<int> eulerPath;
        stk.push(startNode);

        while (!stk.empty()) {
            int node = stk.top();

            if (!graph[node].empty()) {
                int nextNode = graph[node].back();
                graph[node].pop_back();
                stk.push(nextNode);
            } else {
                eulerPath.push_front(node);
                stk.pop();
            }
        }

        // Convert Eulerian path into the required arrangement
        vector<vector<int>> result;
        auto it = eulerPath.begin();
        while (it + 1 != eulerPath.end()) {
            result.push_back({*it, *(it + 1)});
            it++;
        }

        return result;
    }
};