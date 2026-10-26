class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int row, int col){
        int n = grid.size();
        int m = grid[0].size();

        // base case - Reached outside the grid
        if(row<0 || row>=n || col<0 || col>=m){
            return false;
        }

        // Water or already visited
        if(grid[row][col] == 1) return true;

        //mark cell as visited
        grid[row][col] = 1;

        // recursive check for up, down, left and right
        bool up = dfs(grid, row-1, col);
        bool down = dfs(grid, row+1, col);
        bool left = dfs(grid, row, col-1);
        bool right = dfs(grid, row, col+1);

        return up && down && left && right;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        //DFS - RECURSION IN TRUE AND FALSE 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    if(dfs(grid, i, j)) //if this returns true
                        count++;
                }
            }
        }
        return count;
    }
};