class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> prefixXOR(n);
        vector<int> answer(n);
        prefixXOR[0] = nums[0];
        for(int i = 1; i < n; i++){
           prefixXOR[i] =  prefixXOR[i - 1] ^ nums[i];
        }
        int mask = 0xFFFFFFFF << maximumBit;
        for(int i = 0; i < n; i++){
           int extract = prefixXOR[n-1-i] & ~(mask);
           answer[i] = ~extract & ~mask;
        }
        return answer;
    }
};