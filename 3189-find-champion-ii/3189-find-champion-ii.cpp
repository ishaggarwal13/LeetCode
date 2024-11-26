class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);

        // Calculate indegree for each team
        for (const vector<int>& edge : edges) {
            indegree[edge[1]]++;
        }

        int champion = -1; // Start with no champion identified

        // Find the team with zero indegree
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (champion != -1) {
                    // More than one team has zero indegree, no single champion
                    return -1;
                }
                champion = i; // Identify the potential champion
            }
        }

        return champion;
    }
};