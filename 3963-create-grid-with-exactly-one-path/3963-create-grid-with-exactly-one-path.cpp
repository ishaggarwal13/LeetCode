class Solution {
public:
    vector<string> createGrid(int m, int n) {
        //make obstacle grid
        vector<string> grid(m, string(n, '#'));

        //fill the first row with free cell
        for(int j=0; j<n; j++){
            grid[0][j] = '.';
        }

        //fill the last column with free cell
        for(int i=0; i<m; i++){
            grid[i][n-1] = '.';
        }

        return grid;
    }
};