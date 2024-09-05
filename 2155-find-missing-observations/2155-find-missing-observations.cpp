class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum1 = accumulate(rolls.begin(), rolls.end(), 0);
        int m = rolls.size();
        int sum2 = mean*(n+m) - sum1;

        if(sum2>6*n || sum2<n) return {};

        int q = sum2/n; //distribution evenly
        int r = sum2%n; //how many 1 we need to add to number to makerolls up sum to sum2
        vector<int> ans(n, q); //declaring vector of size n and value to it as q
        for(int i=1; i<=r; i++){
            ans[i]++;
        }
        return ans;
    }
};