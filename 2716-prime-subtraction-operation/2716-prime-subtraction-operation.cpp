class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> prime(1000,true);
        for(int i=2;i *i<1000;i++)
        {
            if(prime[i])
            {
                for(int j=2;j*i<1000;j++)
                {
                    prime[j*i]=false;
                }
            } 
        }
        int n=nums.size();
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            continue;
            else
            {
                bool flag=true;
                for(int j=2;j<nums[i];j++)
                {
                    if(prime[j] && (nums[i]-j)<nums[i+1])
                    {
                        nums[i]=nums[i]-j;
                        flag=false;
                        break;
                    }
                }
                if(flag)
                return false;

            }
        }
        return true;
    }
};