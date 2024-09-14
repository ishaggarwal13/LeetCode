class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> s;

        for(int i=0; i<word.size(); i++){
            if(isdigit(word[i])){
                string ans = "";
                while(i<word.size() && word[i] == '0') i++;
                
                while(i<word.size() && isdigit(word[i])){
                    ans += word[i];
                    i++;
                }
                s.insert(ans);
            }
        }
        return s.size();
    }
};