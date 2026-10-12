class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        for(int i=1; i<=s.size(); i++){
            char c = s[0]; //first char
            s.erase(s.begin()); //remove first char
            s += c;
            if(s == goal) return true;
        }
        return false;
    }
};