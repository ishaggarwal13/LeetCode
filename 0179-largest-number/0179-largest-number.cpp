class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for(auto i : nums){
            temp.push_back(to_string(i));
        }
        //use custom compare function
        sort(temp.begin(), temp.end(), [](const string &a, const string &b){
            return (b + a) < (a + b);
        });

        string ans;
        for(const auto& num : temp){
            ans += num;
        }
        if(nums[0] == 0) return "0";
        return ans;
    }
};