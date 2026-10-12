class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, char> mps;
        unordered_map<char, char> mpt;
        int n = s.size();

        for(int i=0; i<n; i++){
            char a = s[i];
            char b = t[i];

            //find if s[i] mapping is preseent and then check is that mapping is done to t 
            if(mps.find(a) != mps.end()){
                if(mps[a] != b) return false;
            }

            if(mpt.find(b) != mpt.end()){
                if(mpt[b] != a) return false;
            }

            mps[a] = b;
            mpt[b] = a;
        }
        return true;
    }
};