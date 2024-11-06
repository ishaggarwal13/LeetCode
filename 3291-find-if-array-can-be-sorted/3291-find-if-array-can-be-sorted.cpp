class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<pair<int, int>> maxmin;
        maxmin.push_back({nums[0], nums[0]});

        for(int i=1; i<nums.size(); i++){
            int curr = __builtin_popcount(nums[i]);
            int prev = __builtin_popcount(nums[i-1]);

            if(curr != prev){
                maxmin.push_back({nums[i], nums[i]});
            }
            maxmin.back().first = min(maxmin.back().first, nums[i]);
            maxmin.back().second = max(maxmin.back().second, nums[i]);
        }

        // check the sort condition for the groups end and start element
        for(int i=1; i<maxmin.size(); i++){
            if(maxmin[i-1].second > maxmin[i].first){
                return false;
            }
        }

        return true;
    }
};