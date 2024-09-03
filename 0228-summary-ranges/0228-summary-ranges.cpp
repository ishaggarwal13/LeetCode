class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size(), i=0, j;
        while(i<n){
            j = i+1; //moving j right
            while(j<n && nums[j-1] + 1 == nums[j]) j++; //increasing j
            //composing and appending the next element to res 
            res.push_back( to_string(nums[i]) + (j-i > 1 ? "->" + to_string(nums[j-1]) : "") );
            //settle i for the next element for new range to j
            i = j;
        }
        return res;
    }
};