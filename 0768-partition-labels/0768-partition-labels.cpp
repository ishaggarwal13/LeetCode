class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]] = i; //stored last occurence of each char
        }
        int start=0, end=0;
        vector<int> ans;
        for(int i=0; i<s.length(); i++){
            end = max(end, mp[s[i]]); //updating the end and storing max value
            if(end == i){
                ans.push_back(end-start+1);
                start = end+1; //update the start for updating the ans value
            }
        }
        return ans;
    }
};