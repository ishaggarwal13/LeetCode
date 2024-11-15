class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if (k==0) return 1;
        int n = nums.size(), ans = 0, i = 0, j = 0, curOr = 0, curAnd = 1, curXor = 0;
        ans = n+1;
        while (i<n) {
            //cout<<"~~~"<<i<<",,,"<<j<<endl;
            //cout<<curOr<<", "<<curAnd<<", "<<curXor<<endl;
            if (curOr<k && j<n) {
                curOr |= nums[j++];
            } else if (curOr>=k) {
                ans = min(ans, j-i);
                i++;
                if (i<n && nums[i]==nums[i-1]) {
                    if (curOr==nums[i])
                        curOr = 0;
                    continue;
                }
                curOr = 0;
                for (int k=i; k<j; ++k) {
                    curOr |= nums[k];
                }
            } else {
                i++;
            }
        }
        return ans>n? -1: ans;
    }
};