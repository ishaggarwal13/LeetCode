class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        //Time: O(m * n)
        //Space : O(m * n)
        if(m*n != original.size()) return {};
        vector<vector<int>> ans(m, vector<int>(n,0));
        for(int i=0; i<original.size(); i++){
            ans[i/n][i%n] = original[i];
        }
        return ans;
    }
};