class Solution {
public:
    int n, m;
    void dfs(vector<vector<int>>& grid, int i, int j, int& a){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == 1){
            a++; //inc by 1 for one island
            grid[i][j] = 0;
            int dir[] = {0,1,0,-1,0};
            for(int k=0; k<4; k++){
                dfs(grid, i+dir[k], j+dir[k+1], a);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int island = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int a = 0;
                dfs(grid, i, j, a);
                island = max(island, a);
            }
        }
        return island;
    }
};