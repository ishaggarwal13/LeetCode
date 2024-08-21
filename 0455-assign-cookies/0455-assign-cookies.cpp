class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //GREEDY ALGO O(NlogN)
        // int n = g.size(); //children array size
        // int m = s.size(); //cokkie array size
        int l = 0, r = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(l < s.size() && r < g.size()){
            if(s[l] >= g[r]){
                r++;
            }
            l++;
        }
        return r;
    }
};