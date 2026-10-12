class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // sort the array of strings
        // first and last string will be most diff can compare its substr and chekc the longest
        sort(strs.begin(), strs.end());
        string ans = "";
        string first = strs[0];
        string last = strs[strs.size()-1];

        int len = min(first.size(), last.size());

        for(int i=0; i<len; i++){
            if(first[i] != last[i]) return ans;
            ans += first[i];
        }
         
        return ans;
    }
};