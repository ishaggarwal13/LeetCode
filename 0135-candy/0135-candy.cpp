class Solution {
public:
    //one pass method - greedy algorithm - O(n) TC & O(1) SC
    int candy(vector<int>& ratings) {
        if(ratings.empty()){
            return 0;
        }

        int n = ratings.size();
        int candy=1, up=0, down=0, peak=0;

        for(int i=1; i<n; i++){
            if(ratings[i-1]<ratings[i]){
                down = 0;
                up += 1;
                peak = up + 1;
                candy += peak;
            } else if(ratings[i - 1] == ratings[i]){
                down = 0;
                up = 0;
                peak = 0;
                candy += 1;
            } else {
                down += 1;
                up = 0;
                candy += down + 1 - (peak > down);
            }
        }

        return candy;
    }
};