class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> a = nums;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        
        vector<int> ans;
        map<int,int> mpp;
        for(int i=0;i<k;i++){
            mpp[nums[i]]++;
        }
        for(int i=0;i<a.size();i++){
            if(mpp.find(a[i]) != mpp.end() && mpp[a[i]] !=0){
                ans.push_back(a[i]);
                mpp[a[i]]--;
            }
        }
        return ans;
    }
};