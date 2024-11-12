class Solution {
public:
    // int getvalue(int row, int col){
    //     if(col == 0 || col == row){
    //         return 1;
    //     }
    //     return getvalue(row-1, col-1) + getvalue(row-1, col);
    // }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows); //using dp
        for(int i=0; i<numRows; i++){ //lines or rows
            dp[i].resize(i+1);
            for(int j=0; j <= i; j++){ //columns
                if(j == i || j == 0){
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
            }
        }
        return dp;
    }
};