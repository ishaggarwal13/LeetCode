class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        //concatenation
        string s = s1 + " " + s2;
        
        unordered_map<string, int> mp;
        string temp = "";
        for(auto& str : s){
            if(str == ' '){
                mp[temp]++; //add word to map
                temp = "";
            } else {
                temp += str;
            }
        }

        if(temp != ""){
            mp[temp]++;
            temp = "";
        }

        vector<string> ans;
        for(auto& m : mp){
            if(m.second == 1){
                ans.push_back(m.first);
            }
        }
        return ans;
    }
};