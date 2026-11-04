class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rf = 0;
        int cf = 0;
        int rl = matrix.size()-1;
        int cl = matrix[0].size()-1;
        vector<int> ans;

        while(rf<=rl && cf<=cl){
            for(int i=cf; i<=cl; i++){
                ans.push_back(matrix[rf][i]);
            }
            rf++;
            for(int j=rf; j<=rl; j++){
                ans.push_back(matrix[j][cl]);
            }
            cl--;
            if(rf<=rl){
                for(int r=cl; r>=cf; r--){
                    ans.push_back(matrix[rl][r]);
                }
                rl--;
            }
            if(cf<=cl){
                for(int c=rl; c>=rf; c--){
                    ans.push_back(matrix[c][cf]);
                }
                cf++;
            }
        }
        return ans;
    }
};