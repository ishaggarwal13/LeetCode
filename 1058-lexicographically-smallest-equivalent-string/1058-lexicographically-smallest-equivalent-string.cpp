class Solution {
public:
    int find(char x, vector<int>& parent){
        if(parent[x] != x){
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }

    void unite(char u, char v, vector<int>& parent){
        int rootU = find(u, parent);
        int rootV = find(v, parent);

        if(rootU == rootV) return;
        else if(rootU < rootV){
            parent[rootV] = rootU;
        } else{
            parent[rootU] = rootV;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        //union & find(disjoint sets)
        //will create a parent vector for int/char to store root of char
        //union two charters and then find its root and set the root to the smallest

        vector<int> parent(26);
        for(int i=0; i<26; i++) parent[i] = i;

        for(int i=0; i<s1.size(); i++){
            char u = s1[i] - 'a';
            char v = s2[i] - 'a';
            unite(u, v, parent);
        }

        string res = "";
        for(char st: baseStr){
            int root = find(st-'a', parent);
            res += (char)(root + 'a');
        }
        
        return res;
    }
};