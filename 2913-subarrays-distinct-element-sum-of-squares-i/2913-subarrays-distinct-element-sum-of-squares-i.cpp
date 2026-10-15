class Solution {
public:
    int sumCounts(vector<int>& nums) {
        // TC O(n^2) SC O(1)
        //loops for subarrays 
        int n = nums.size();
        int res = 0;
        for(int i=0; i<n; i++){
            int freq[101] = {0}; // to reduce space freq array
            int count = 0;
            for(int j=i; j<n; j++){
                if(freq[nums[j]] == 0) count++;

                freq[nums[j]]++;

                res += count * count;
            }
        }
        return res;
    }
};