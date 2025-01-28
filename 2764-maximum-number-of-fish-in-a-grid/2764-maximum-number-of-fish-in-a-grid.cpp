class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c] == 0){
            return 0;
        }

        int total = grid[r][c];
        grid[r][c] = 0;

        total += dfs(grid, r+1, c);
        total += dfs(grid, r, c+1);
        total += dfs(grid, r-1, c);
        total += dfs(grid, r, c-1);

        return total;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish=0;
        int row = grid.size();
        int col = grid[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                //check if cell is not 0 and cell is not visisted
                if(grid[i][j] > 0){
                    maxFish = max(maxFish, dfs(grid, i, j));
                }
            }
        }
        return maxFish;
    }
};