class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        //O(n) & O(1) greedy
        int sum1 = accumulate(rolls.begin(), rolls.end(), 0);
        int m = rolls.size();
        int sum2 = mean*(n+m) - sum1;

        if(sum2>6*n || sum2<n) return {};

        vector<int> ans(n, 1); //asigning every value in n size vector to 1
        sum2 -= n; //removing 1's n from the sum
        int i=0;
        while(sum2>0){
            while(sum2>0 && ans[i]<6){
                ans[i]++;
                sum2--;
            }
            if(sum2>0){
                i++;
            }
        }
        return ans;
    }
};