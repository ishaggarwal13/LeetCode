class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        ans.push_back(s[0]);

        int count = 1;
        for(int i=1; i<s.size(); i++){
            // if equal then inc count and check for count < 3 and add the char to ans
            // skip the third same char
            if(s[i] == ans.back()){
                count++;
                if(count < 3) ans.push_back(s[i]);
            } else{
                // reassign count to 1
                // and add the char to ans
                count = 1;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};