class Solution {
public:
    int solve(int i, int j, string& s, vector<vector<int>>& dp) {
        //O(n^2 dp call * n recursive n calls) = O(n^3) TC
        //O(n^2) SC
        if(i==j) return 1; //one chracter one turn to print
        if(dp[i][j] != -1) return dp[i][j];

        int minTurns = INT_MAX;
        for(int k=i; k<j; k++){ //for every k divide the string into [i,k] & [k+1,j]
            minTurns = min(minTurns, solve(i, k, s, dp) + solve(k+1, j, s, dp));
        }
        //edge case 
        return dp[i][j] = (s[i] == s[j]) ? minTurns-1 : minTurns;
    }
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(0, n-1, s, dp);
    }
};