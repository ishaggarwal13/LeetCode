class Solution {
public:
    long long dfs(vector<vector<int>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();

        //base case
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 0) return 0;

        // add sum and mark the current cell to 0
        long long sum = grid[i][j];
        grid[i][j] = 0;

        long long up = dfs(grid, i-1, j);
        long long down = dfs(grid, i+1, j);
        long long left = dfs(grid, i, j-1);
        long long right = dfs(grid, i, j+1);

        return (sum+up+down+left+right);
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] > 0){
                    long long sum = dfs(grid, i, j);
                    if(sum % k == 0) count++;
                }
            }
        }
        return count;
    }
};