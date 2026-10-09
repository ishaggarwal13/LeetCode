class Solution {
public:
    //o(n) & o(1)
    int minInsertions(string s) {
        int open = 0;
        int ans = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(') open++;
            else {
                //step 1: make a '))'
                if(i+1 < s.length() && s[i+1] == ')') i++;
                else ans++;
                //step 2: find its '('
                if(open > 0) open--;
                else ans++;
            }
        }
        return ans + open * 2;
    }
};