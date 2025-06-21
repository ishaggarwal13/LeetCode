class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>mp;
        int n = word.size(), count = INT_MAX , mini = INT_MAX;
        for (char c:word){
            mp[c]++;
        }
        for (auto pair: mp){
            int curr = 0; 
            for (auto m : mp){
                curr += (m.second<pair.second) ? m.second : max(0, m.second-(pair.second+k));
            }
            count=min(count,curr);
        }
        return count;
    }
};