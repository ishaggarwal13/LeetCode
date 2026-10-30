class Solution {
public:
    // by removing boundary connected islands first 
    // then counting for rest inbetween 
    // O(n x m) TC and O(n x m) SC
    void dfs(vector<vector<int>>& grid, int row, int col){
        int n = grid.size();
        int m = grid[0].size();

        // base case - Reached outside the grid
        if(row<0 || row>=n || col<0 || col>=m || grid[row][col] == 1){
            return;
        }

        //mark cell as visited
        grid[row][col] = 1;

        // recursive check for up, down, left and right
        dfs(grid, row-1, col);
        dfs(grid, row+1, col);
        dfs(grid, row, col-1);
        dfs(grid, row, col+1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Step 1: Remove boundary-connected islands
        for(int i=0; i<n; i++){
            dfs(grid, i, 0);
            dfs(grid, i, m-1);
        }

        for(int j=0; j<m; j++){
            dfs(grid, 0, j);
            dfs(grid, n-1, j);
        }

        // Step 2: Count remaining islands
        int count = 0;
        //DFS - RECURSION
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};