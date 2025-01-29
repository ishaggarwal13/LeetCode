class Solution {
public:
    vector<int> parent;
    int find(int num){
        return (parent[num] == num) ? num : find(parent[num]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        if(edges.size()<=0) return {};
        parent.resize(edges.size()+1);

        for(int i=1; i<=edges.size(); i++){
            parent[i] = i;
        }

        for(auto edge : edges){
            int f1 = find(edge[0]);
            int f2 = find(edge[1]);
            if(f1!=f2){
                parent[f1] = f2;
            } else {
                return edge;
            }
        }

        return {};
    }
};