class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> ans;

        vector<int> preffix(n);
        preffix[0] = arr[0];

        for(int i=1; i<n; ++i){
            preffix[i] = preffix[i-1] ^ arr[i]; //storing xor values from start
        }

        for(const auto& q : queries){
            int start = q[0];
            int end = q[1];

            ans.push_back(start>0 ? (preffix[start-1]^preffix[end]) : preffix[end]);
        }
        return ans;
    }
};