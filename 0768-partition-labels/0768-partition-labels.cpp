class Solution {
public:
    vector<int> partitionLabels(string s) {
        int m[256] = {0};
        unordered_set<char> mp;

        for(int i=0; i<s.length(); i++){
            m[s[i]] = i; //stored last occurence of each char in arr
        }

        vector<int> ans;

        for(int i=0, j=-1; i<s.length(); i++){
            if(m[s[i]] == i){
                if(mp.erase(s[i]); empty(mp))
                    ans.push_back(i-j), j=i;
                else;
            } else{
                mp.insert(s[i]);
            }
        }
        return ans;
    }
};