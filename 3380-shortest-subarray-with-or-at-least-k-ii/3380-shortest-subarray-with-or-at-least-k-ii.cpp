class Solution {
public:
    int fun(vector<int> &v){
        int ans=0;
        for(int i=0;i<31;i++){
            if(v[i]>0){
                ans+=(1<<i);
            }
        }
        return ans;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if(k==0){
            return 1;
        }
        vector<int>v(31,0);
        int n=nums.size();
        int j=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int val=fun(v);
            //cout<<val<<endl;
            while(val>=k){
                ans=min(ans,i-j);
                //cout<<j<<" "<<i<<" "<<val<<endl;
                int num=nums[j];
                int cnt=0;
                while(num>0){
                    //cout<<num<<endl;
                    v[cnt]-=(num &1);
                    num=num>>1;
                    cnt++;
                }
                j++;
                val=fun(v);
            }
                int num=nums[i];
                int cnt=0;
                while(num){
                    v[cnt]+=(num &1);
                    num=num>>1;
                    cnt++;
                }
        }
        int val=fun(v);
       while(val>=k){
                ans=min(ans,n-j);
                //cout<<j<<" "<<i<<" "<<val<<endl;
                int num=nums[j];
                int cnt=0;
                while(num>0){
                    //cout<<num<<endl;
                    v[cnt]-=(num &1);
                    num=num>>1;
                    cnt++;
                }
                j++;
                val=fun(v);
            }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};