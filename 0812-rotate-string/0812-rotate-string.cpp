class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        return (s+s).find(goal) != string::npos;
        // this is working as concat s+s in which find function used to 
        // find teh substring goal is found return the first index occourence
        // other null which is represented by string::npos(a const indicate the invalid pos)
    }
};