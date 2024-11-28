class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue< tuple<int, int, int> , vector<tuple<int , int, int>>  , greater<tuple<int, int, int >> > pq;

        pq.push({grid[0][0] , 0 , 0});
        grid[0][0] = 2;
        vector<int> dir = {0 , 1 , 0, -1 , 0};

        while(!pq.empty()){
            auto tp = pq.top();
            pq.pop();
            int bricks = get<0>(tp) , x= get<1>(tp) , y = get<2>(tp);
            // cout << x << " " << y << endl;
            for(int i = 0 ; i < 4 ; i++){
                int newX = x + dir[i];
                int newY = y + dir[i+1];

                if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] != 2){
                    if(newX == grid.size()-1 && newY == grid[0].size()-1)return bricks;
                    pq.push({bricks + grid[newX][newY] ,  newX , newY});
                    grid[newX][newY] = 2;
                }
            }
        }

        return -1;
    }
};