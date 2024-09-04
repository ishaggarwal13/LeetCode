class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        //time complexity is O(N + K) and space complexity is O(K), 
        unordered_set<string> s;
        for(auto& obstacle : obstacles){
            s.insert( to_string(obstacle[0]) + "," + to_string(obstacle[1]) );
        }

        int x=0, y=0, dx=0, dy=1; //(dx,dy) (0,1) for north position
        int ans=0;

        for(auto i : commands){
            if(i == -1){
                int temp = dx;
                dx = dy;
                dy = -temp;
            } else if(i == -2){
                int temp = dx;
                dx = -dy;
                dy = temp;
            } else {
                for(int j = 0; j<i; j++){
                    int xx = x + dx;
                    int yy = y + dy;

                    if(s.find( to_string(xx) + "," + to_string(yy) ) != s.end())
                        break;
                    x = xx;
                    y = yy;
                    ans = max(ans, x*x + y*y);
                }
            }
        }
        return ans;
    }
};