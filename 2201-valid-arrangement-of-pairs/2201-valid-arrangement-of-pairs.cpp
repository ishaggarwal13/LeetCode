class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_set<int> node_set;
        unordered_map<int, int> indegree_map, outdegree_map;
        unordered_map<int, unordered_set<int>> neighbour_map;
        for (int i = 0; i < pairs.size(); i++) {
            int u = pairs[i][0], v = pairs[i][1];
            node_set.insert(u);
            node_set.insert(v);
            outdegree_map[u]++;
            indegree_map[v]++;
            neighbour_map[u].insert(v);
        }

        // Determine the starting point.
        int current = *node_set.begin();
        for (int node : node_set) {
            if (indegree_map.find(node) == indegree_map.end()) {
                indegree_map[node] = 0;
            }
            if (outdegree_map.find(node) == outdegree_map.end()) {
                outdegree_map[node] = 0;
            }
            if (outdegree_map[node] - indegree_map[node] == 1) {
                current = node;
                break;
            }
        }

        // Find the Eulerian path.
        stack<int> node_stack;
        vector<vector<int>> result;
        while (true) {
            if (!neighbour_map[current].empty()) {
                node_stack.push(current);
                int next = *(neighbour_map[current].begin());
                neighbour_map[current].erase(next);
                current = next;
            } else {
                if (!node_stack.empty()) {
                    int prev = node_stack.top();
                    node_stack.pop();
                    result.push_back({prev, current});
                    current = prev;
                } else {
                    break;
                }
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};