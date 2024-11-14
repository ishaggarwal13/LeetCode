class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
        
        if(sum<p){
            return -1;
        }
        sum=sum%p;
        if(sum==0){
            return 0;
        }
        unordered_map<int,int> hash;
        int currsum=0;
        int minlen=INT_MAX;
        hash[0]=-1;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            currsum%=p;
    
            if(hash.find((currsum-sum+p)%p)!=hash.end()){
                minlen=min(minlen,i-hash[(currsum-sum+p)%p]);
            }
            hash[currsum]=i;
        }
        if(minlen==INT_MAX || minlen==nums.size()){
            return -1;
        }
        return minlen;
    }
};