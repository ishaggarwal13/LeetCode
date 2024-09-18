class Solution {
public:
    string largestNumber(vector<int>& nums) {
        //use custom compare function
        sort(nums.begin(), nums.end(), [](const auto a, const auto b){
            return (to_string(a) + to_string(b)) > (to_string(b) + to_string(a));
        });

        string ans = "";
        for(int i=0; i<nums.size(); i++){
            ans += to_string(nums[i]);
        }
        if(nums[0] == 0) return "0";
        return ans;
    }
};