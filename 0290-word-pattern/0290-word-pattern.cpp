class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string word;
        stringstream in(s);
        while(in >> word){
            v.push_back(word); //pushing word into vector
        }
        if(pattern.size() != v.size())
            return false;
        
        unordered_map<char, string> p;
        unordered_map<string, char> mp;

        for(int i=0; i<v.size(); i++){
            if(p.find(pattern[i]) != p.end() && p[pattern[i]] != v[i]){ 
                //if key is not find or the value of key is not same
                return false;
            } else if(mp.find(v[i]) != mp.end() && mp[v[i]] != pattern[i]){
                return false;
            }
            p[pattern[i]] = v[i]; //storing with a -> dog key->value
            mp[v[i]] = pattern[i]; //storing with dog->a key->value
        }
        return true;
    }
};