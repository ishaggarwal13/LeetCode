class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> vecValToIndex;
        for(int i = 0; i < nums.size(); i++) {
            vecValToIndex.push_back({nums[i], i});
        }
        sort(vecValToIndex.begin(), vecValToIndex.end(), 
            [](const std::pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
        });

        sort(vecValToIndex.begin(), vecValToIndex.begin() + k, 
            [](const std::pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
        });

        vector<int> result;
        for(int i = 0; i < k; i++) result.push_back(vecValToIndex[i].first);
        return result;
    }
};