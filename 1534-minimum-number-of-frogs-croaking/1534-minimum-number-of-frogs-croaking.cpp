class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int ongoing = 0;
        int maxongoing = 0;
        vector<int> dp(5,0);
        for(char c : croakOfFrogs){
            if(c == 'c'){
                dp[0]++;
                ongoing++;
                maxongoing = max(maxongoing, ongoing);
            } else {
                if(c == 'r'){
                    if(dp[0] <= dp[1]) return -1;
                    dp[1]++;
                } else if(c == 'o'){
                    if(dp[1] <= dp[2]) return -1;
                    dp[2]++;
                } else if(c == 'a'){
                    if(dp[2] <= dp[3]) return -1;
                    dp[3]++;
                } else if(c == 'k'){
                    if(dp[3] <= dp[4]) return -1;
                    dp[4]++;
                    ongoing--;
                }
            }
        }
        int total = dp[0];
        for(int i=0; i<5; i++){
            if(dp[i] != total) return -1;
        }
        return maxongoing;
    }
};