class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        
        int n=nums.size();
        int res=0,cnt=0;
        for(int i=0;i<(1<<n);i++)
        {
            int ans=0;
            for(int j=0;j<n;j++)
            {
                 if ((i & (1 << j)) != 0) {
                    //cout<<nums[j]<<" ";
                    ans|=nums[j];
                 }
            }
            //cout<<"hj";
            if(res<ans)
            {
                res=ans;
                cnt=1;
            }
            else if(res==ans){
                cnt++;
            }
        }
        return cnt;
    }
};