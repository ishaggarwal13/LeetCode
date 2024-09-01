class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        //Time: O(m * n)
        //Space : O(m * n)
        if(m*n != original.size()) return {};
        vector<vector<int>> ans(m);
        for(int i=0; i<m; i++){
            ans[i].assign(original.begin()+i*n, original.begin()+(i+1)*n);
        }
        return ans;
    }
};