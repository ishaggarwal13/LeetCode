class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int lst=-1,n=nums.size();
        vector<int> arr(n,-1);
        arr[0]=0;lst=0;
        for(int i=1;i<n;i++){
            if(!((nums[i]&1)^(nums[i-1]&1))){
                lst=i;
            }
            arr[i]=lst;
        }
        vector<bool> ans;
        for(auto&a:queries){
            if(arr[a[0]]!=arr[a[1]]) ans.push_back(0);
            else ans.push_back(1);
        }
        return ans;
    }
};