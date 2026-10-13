class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        //squares array
        int n = nums.size();
        vector<long long> sq(n);
        for(int i=0; i<n; i++){
            sq[i] = 1LL * nums[i] * nums[i];
        }

        //sort the sq array in dec order
        sort(sq.rbegin(), sq.rend());

        //find middle and add first half and sub second half
        int pos = (n + 1)/2;
        long long ans = 0;
        for(int i=0; i<n; i++){
            if(pos>i) ans += sq[i];
            else ans -= sq[i];
        }
        return ans;
    }
};