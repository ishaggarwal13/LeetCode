class Solution {
    int n, m;
    int dir[] = {0, 1, 0, -1, 0};
    private void dfs(int[][] grid, int i, int j, int[] a){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == 1){
            a[0]++;
            grid[i][j] = 0;

            for(int k=0; k<4; k++){
                int nr = i + dir[k];
                int nc = j + dir[k+1];
                dfs(grid, nr, nc, a);
            }
        }
    }
    public int maxAreaOfIsland(int[][] grid) {
        n = grid.length;
        m = grid[0].length;
        int area = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //as in java there is no reference by value so we can use array as they are mutable or the wrapper class
                int[] a = {0};
                dfs(grid, i, j, a);
                area = Math.max(area, a[0]);
            }
        }
        return area;
    }
}