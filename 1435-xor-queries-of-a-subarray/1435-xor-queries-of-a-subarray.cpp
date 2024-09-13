class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        //inbuilt function in stl lib
        partial_sum(arr.begin(), arr.end(), arr.begin(), bit_xor<int>());
        vector<int> ans;
        for(const auto& q : queries){
            int start = q[0], end = q[1];
            ans.push_back(start>0 ? (arr[start-1] ^ arr[end]) : arr[end]);
        }
        return ans;
    }
};