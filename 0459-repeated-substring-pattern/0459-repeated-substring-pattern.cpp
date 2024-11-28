class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 1; i <= s.length()/2; i++){
            if(not ((s.length()%(i))== 0)) continue;

            string sub = s.substr(0, i);
            for(int j = 0; j < s.length(); j++){
                if(s[j] != sub[j%i]) break;
                if(j==s.length()-1) return true;                
            }

        }  
        return false;
        
    }
};