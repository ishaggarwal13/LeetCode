class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        //building teh graph and then use DFS to find smalledt lexi char
        int n = s1.size();
        unordered_map<char, vector<char>> adj;

        //building graph
        for(int i=0; i<n; i++){
            char u = s1[i];
            char v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // replace char with smallest
        string result;
        for(auto base : baseStr){
            vector<int> vis(26, 0);
            char miniChar = dfs(adj, base, vis);
            result.push_back(miniChar);
        }
        return result;
    }

    char dfs(unordered_map<char, vector<char>>& adj, char base, vector<int>& vis){
        vis[base - 'a'] = 1;
        char miniChar = base;
        for(char u : adj[base]){
            if(vis[u-'a'] == 0){
                miniChar = min(miniChar, dfs(adj, u, vis));
            }
        }
        return miniChar;
    }
};