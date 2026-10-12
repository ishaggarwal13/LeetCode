class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        string concat = s+s;
        return concat.find(goal) != string::npos;
    }
};