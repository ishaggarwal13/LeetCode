class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string word;
        stringstream in(s);
        int i=0, n = pattern.size();
        unordered_map<char, int> p;
        unordered_map<string, int> mp;

        //extracting the word from s and compare
        for(word; in>>word; i++){
            if(i==n || p[pattern[i]] != mp[word]){
                return false;
            }
            p[pattern[i]] = mp[word] = i+1;
        }
        
        return i==n;
    }
};