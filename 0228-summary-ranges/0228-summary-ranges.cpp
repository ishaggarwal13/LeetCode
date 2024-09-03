class Solution {
public:
    void pushRes(vector<string>& res, int start, int end){
        if(start != end){
            res.push_back(to_string(start) + "->" + to_string(end));
        } else {
            res.push_back(to_string(start));
        }
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size() == 0) return res;
        int start = nums[0], end = nums[0];

        for(int i=1; i<nums.size(); i++){
            if(nums[i] == 1+nums[i-1]){
                end = nums[i]; // inc end till the end of continous range
            } else{
                pushRes(res, start, end); //otherwise add the start and end of range 1 into array
                start = nums[i]; //assign both start and end to curr element
                end = nums[i];
            }
        }
        pushRes(res, start, end);
        return res;
    }
};