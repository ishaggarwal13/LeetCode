class Solution {
    private int dfs(int[][] grid, int i, int j){
        int dir[] = {-1,0,1,0,-1};
        if(i<0 || i>=grid.length || j<0 || j>=grid[0].length || grid[i][j]==0){
            return 0;
        }
        int total = grid[i][j];
        grid[i][j] = 0;

        for(int k=0; k<4; k++){
            total += dfs(grid, i+dir[k], j+dir[k+1]);
        }
        return total;
    }

    public int findMaxFish(int[][] grid) {
        int row = grid.length, col = grid[0].length;
        int maxFish = 0;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] > 0){
                    maxFish = Math.max(maxFish, dfs(grid, i, j));
                }
            }
        }
        return maxFish;
    }
}