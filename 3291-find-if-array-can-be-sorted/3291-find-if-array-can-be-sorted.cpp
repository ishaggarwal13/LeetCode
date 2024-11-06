class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int> bits;
        for(auto num : nums){
            int count = countBits(num);
            bits.push_back(count);
        }

        int prevMax = INT_MIN;
        for(int i=0; i<nums.size();){
            int start= i;
            int end = i;
            int currMax = INT_MIN, currMin = INT_MAX;
            while (end < nums.size() && bits[end] == bits[start]) {
                currMax = max(currMax, nums[end]);
                currMin = min(currMin, nums[end]);
                end++;
            }
            i = end;
            if(currMin < prevMax) return false;
            prevMax = currMax;
        }
        return true;
    }

    int countBits(int num){
        int count = 0;
        while(num > 0){
            if(num & 1){
                count++;
            }
            num >>= 1; // right shift
        }
        return count;
    }
};