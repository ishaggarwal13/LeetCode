class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int even = 1;
        int odd = 0;
        long long ans = 0;
        int sum = 0;

        for(auto x : arr){
            sum = (sum + x) % 2; //prefix partiy to check even or odd
            if(sum == 1){
                ans = (ans + even) % MOD;
                odd++;
            } else {
                ans = (ans + odd) % MOD;
                even++;
            }
        }
        return ans;
    }
};