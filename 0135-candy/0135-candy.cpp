class Solution {
public:
    //two pass method - greedy algorithm
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candy(n, 1);

        //left to right pass
        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                candy[i] = candy[i-1]+1;
            }
        }

        //right to left pass
        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                candy[i] = max(candy[i], candy[i+1]+1);
            }
        }

        int total=0;
        for(auto c : candy){
            total += c;
        }

        return total;
    }
};