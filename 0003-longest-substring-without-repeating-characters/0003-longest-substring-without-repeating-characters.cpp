class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxi = 0, start = -1;
        for(int i=0; i<s.size(); i++){
            if(dict[s[i]] > start){ //if the word is already exsit in vector then it will change the starting poition of substring
                start = dict[s[i]];
            }
            dict[s[i]] = i; //setting char into dict
            maxi = max(maxi, i - start); //finding maximum length
        }
        return maxi;
    }
};