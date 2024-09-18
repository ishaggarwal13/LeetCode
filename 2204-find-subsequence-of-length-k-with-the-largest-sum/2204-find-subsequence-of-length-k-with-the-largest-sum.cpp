class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i=0; i<n; i++) {
            if (pq.size() < k) {
                pq.push({nums[i], i});
            } else if (pq.top().first < nums[i]) {
                pq.pop();
                pq.push({nums[i], i});
            }
        }

        vector<int> mark(n, 0), res;
        while (!pq.empty()) {
            mark[pq.top().second] = 1;
            pq.pop();
        }
        for (int i=0; i<n; i++) {
            if (mark[i] == 1) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};