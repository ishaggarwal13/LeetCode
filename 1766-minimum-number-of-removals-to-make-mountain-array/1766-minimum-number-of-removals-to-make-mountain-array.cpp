class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {

        int n=nums.size();
        vector<int>right(n,0);
        vector<int>left(n,0);
        vector<int>dp;
        dp.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>dp.back())
            {
                dp.push_back(nums[i]);
                left[i]=dp.size();
            }
            else
            {
                int ind=lower_bound(dp.begin(), dp.end(), nums[i])-dp.begin();
                dp[ind]=nums[i];
                left[i]=ind+1;
            }
        }
        dp.clear();
        dp.push_back(nums[n-1]);
        for(int i=n-2;i>-1;i--)
        {
            if(nums[i]>dp.back())
            {
                dp.push_back(nums[i]);
                right[i]=dp.size();
            }
            else
            {
                int ind=lower_bound(dp.begin(), dp.end(), nums[i])-dp.begin();
                dp[ind]=nums[i];
                right[i]=ind+1;
            }
        }
        int ans=n;
        for(int i=1;i<n-1;i++)
        {
            if(left[i]>1 && right[i]>1)
            {
                ans=min(ans, n - (left[i] + right[i] - 1));
            }
        }
        return ans;
        
    }
};