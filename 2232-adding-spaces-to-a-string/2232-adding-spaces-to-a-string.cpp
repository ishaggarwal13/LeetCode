class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int idxSpace = 0;
        string res;
        spaces.push_back(s.size());
        for (int i = 0; i < s.size(); i++){
            if(i == spaces[idxSpace]) {
                res += ' ';
                idxSpace++;
            }
            res += s[i];
        }
        return res;
    }
};