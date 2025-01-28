class Solution {
public:
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

    int dfs(vector<vector<int>>& grid, int row, int col){
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col] == 0){
            return 0;
        }

        int total = grid[row][col];
        grid[row][col] = 0;

        vector<vector<int>> directions = {{0,1}, {0,-1}, {-1,0}, {1,0}};

        for(const auto& it : directions){
            int newRow = row + it[0];
            int newCol = col + it[1];
            total += dfs(grid, newRow, newCol);
        }
        return total;
    }
};