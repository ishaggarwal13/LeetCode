class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        //O(n^2) and O(n)
        unordered_map<int,int> mp;
        int count=0; 
        int n = nums.size();

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                mp[nums[i] + nums[j]]++;
            }
            for(int k=i+2; k<n; k++){
                count+=mp[nums[k] - nums[i+1]];
            }
        }
        return count;
    }
};