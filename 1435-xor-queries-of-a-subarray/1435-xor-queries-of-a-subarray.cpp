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

        for(int i=0; i<queries.size(); i++){
            int start = queries[i][0];
            int end = queries[i][1];

            if(start == 0) {
                ans.push_back(preffix[end]);
            } else {
                ans.push_back(preffix[start-1]^preffix[end]);
            }
        }
        return ans;
    }
};