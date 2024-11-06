class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        for(int i=1; i<=s.size(); i++){
            char temp = s[0]; // storing first begin char

            s.erase(s.begin()); // remove first char
            s += temp; // add first element to last at back

            if(s == goal) return true; // check for the string
        }

        return false;
    }
};