class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& ans) {
        ans.push_back(path);
        for(int i=start; i<nums.size(); i++){
            path.push_back(nums[i]);
            backtrack(nums, i+1, path, ans);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int start = 0;
        backtrack(nums, start, path, ans);
        return ans;
    }
};