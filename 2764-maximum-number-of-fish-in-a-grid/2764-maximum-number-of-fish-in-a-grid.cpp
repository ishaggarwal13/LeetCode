class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish=0;
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<vector<int>> directions = {{0,1}, {0,-1}, {-1,0}, {1,0}};

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                //check if cell is not 0 and cell is not visisted
                if(grid[i][j] > 0 && !visited[i][j]){
                    int catchFish = dfs(grid, visited, directions, i, j);
                    maxFish = max(maxFish, catchFish);
                }
            }
        }
        return maxFish;
    }

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<vector<int>>& directions, int row, int col){
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || visited[row][col] || grid[row][col] == 0){
            return 0;
        }

        visited[row][col] = true;
        int total = grid[row][col];

        for(const auto& it : directions){
            int newRow = row + it[0];
            int newCol = col + it[1];
            total += dfs(grid, visited, directions, newRow, newCol);
        }
        return total;
    }
};