class Solution {
public:
    vector<string> makeVector(string s){
        stringstream ss(s);
        vector<string> ans;
        string temp;
        while(ss >> temp){
            ans.push_back(temp);
        }
        return ans;
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> v1 = makeVector(s1);
        vector<string> v2 = makeVector(s2);
        vector<string> ans;
        unordered_map<string, int> mp;

        for(const auto& str : v1){
            mp[str]++;
        }

        for(const auto& str : v2){
            mp[str]++;
        }

        for(auto& m : mp){
            if(m.second == 1){
                ans.push_back(m.first);
            }
        }
        return ans;
    }
};