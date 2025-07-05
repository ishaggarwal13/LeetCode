class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto a : arr){
            mp[a]++;
        }

        int maxi = -1;
        for(auto m : mp){
            if(m.second == m.first){
                maxi = max(maxi, m.first);
            }
        }

        return maxi;
    }
};