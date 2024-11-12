class Solution {
public:
    vector<int> getRow(int row) {
       vector<vector<int>> dp(row + 1); // 2D vector to hold the triangle
    for (int i = 0; i <= row; i++) { // Build triangle row by row
        dp[i].resize(i + 1); // Resize the current row
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1; // The first and last elements are 1
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; // Sum of two above
            }
        }
    }
    return dp[row];
    }
};