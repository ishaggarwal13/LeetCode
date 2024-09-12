class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = words.size();
        bool arr[26] = {};
        //mark true for the char in allowed
        for(char c : allowed) arr[c - 'a'] = true;
        for(auto word : words){
            for(char c : word){
                if(!arr[c - 'a']){ //if a char is diff from allowed then it will reduce res and break the loop
                    res--;
                    break;
                }
            }
        }
        return res;
    }
};