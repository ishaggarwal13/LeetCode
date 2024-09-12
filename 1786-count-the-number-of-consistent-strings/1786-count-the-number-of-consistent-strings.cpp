class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0;
        bool arr[26] = {};
        //mark true for the char in allowed
        for(char c : allowed) arr[c - 'a'] = true;

        for(auto word : words){
            bool flag = true;
            for(char c : word){
                if(!arr[c - 'a']){ //if a char is diff from allowed then it will change flag and break the loop
                    flag = false;
                    break;
                }
            }
            if(flag) res++;
        }
        return res;
    }
};