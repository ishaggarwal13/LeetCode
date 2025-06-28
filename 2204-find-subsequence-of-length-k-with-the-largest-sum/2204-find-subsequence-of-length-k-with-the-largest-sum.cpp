class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> pq;
        //storing number like a pair with its index
        for(int i=0; i<nums.size(); i++){
            pq.push_back({nums[i], i});
        }

        //sort the pq in dec order for keeping greater num at first
        sort(pq.begin(), pq.end(), [](auto& a, auto& b){
            return a.first > b.first;
        });

        //resizeing pq till k length
        pq.resize(k);

        //sort back acc to index
        sort(pq.begin(), pq.end(), [](auto& a, auto& b){
            return a.second < b.second;
        });

        vector<int> ans;
        for(auto& [var, idx] : pq){
            ans.push_back(var);
        }

        return ans;
    }
};