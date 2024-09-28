class Solution {
public:
    vector<int> dr = {1,-1,0,0};
    vector<int> dc = {0,0,-1,1};
    int maxGold=0;

    int dfs(vector<vector<int>>& grid, int x, int y, int n, int m){
        if(x<0 || x>=n || y<0 || y>=m || grid[x][y] ==0 )
            return 0;
        
        int curr = grid[x][y];
        grid[x][y]=0;
        int local = curr;

        //directions
        for(int i=0; i<4; i++){
            int newX = x+dr[i];
            int newY = y+dc[i];
            local = max(local, curr + dfs(grid, newX, newY, n, m));
        }

        grid[x][y] = curr;
        return local;

    }


    int getMaximumGold(vector<vector<int>>& grid) {
        int row = grid.size();
        int colmuns = grid[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<colmuns; j++){
                if(grid[i][j] != 0){
                    maxGold = max(maxGold, dfs(grid, i, j, row,colmuns));
                }
            }
        }
        return maxGold; 
    }
};