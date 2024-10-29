class Solution {
public:
    bool isValid(int row, int col, int rowSize, int colSize){
        if(row<0 || row>=rowSize || col>=colSize){
            return false;
        }
        return true;
    }

    int findMaxMoves(vector<vector<int>>& grid, int row, int col, int rowSize, int colSize, vector<vector<int>> &dp){
        if(row<0 || row>=rowSize || col>=colSize){
            return 0;
        }

        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int currentCell = grid[row][col];
        int down=0;
        int downLeft=0;
        int downRight=0;
        if(isValid(row,col+1,rowSize,colSize) && grid[row][col+1] > currentCell){
            down = 1 + findMaxMoves(grid,row,col+1,rowSize,colSize,dp);
        }
        if(isValid(row+1,col+1,rowSize,colSize) && grid[row+1][col+1] > currentCell){
            downRight = 1 + findMaxMoves(grid,row+1,col+1,rowSize,colSize,dp);
        }
        if(isValid(row-1,col+1,rowSize,colSize) && grid[row-1][col+1] > currentCell){
            downLeft = 1 + findMaxMoves(grid,row-1,col+1,rowSize,colSize,dp);
        }

        return dp[row][col] =  max(down,max(downLeft,downRight));
        
    }

    int maxMoves(vector<vector<int>>& grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        int ans=0;
        vector<vector<int>> dp(rowSize,vector<int>(colSize,-1));
        for(int i=0;i<rowSize;i++){
            ans=max(ans,findMaxMoves(grid,i,0,rowSize,colSize,dp));
        }
        return ans;
    }
};