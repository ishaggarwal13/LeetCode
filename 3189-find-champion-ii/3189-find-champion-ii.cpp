class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> in(n+1,0);

        for(int i=0;i<edges.size();i++)
        {
            in[edges[i][1]]++;
        }

        int ans;
        int ct=0;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            {
                ans=i;
                ct++;
            }

            if(ct==2)
            return -1;
        }

        return ans;
    }
};