class Solution {
public:
    int numDifferentIntegers(string word) {
        vector<string> v;

        for(int i=0; i<word.size(); i++){
            if(isdigit(word[i]) == true){
                string ans = "";
                while(word[i] == '0') i++;
                while(isdigit(word[i]) == true){
                    ans += word[i];
                    i++;
                }
                v.push_back(ans);
            }
        }

        unordered_set<string> s;
        for(int i=0; i<v.size(); i++){
            s.insert(v[i]);
        }
        return s.size();
    }
};