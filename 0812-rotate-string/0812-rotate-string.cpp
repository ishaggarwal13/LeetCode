class Solution {
private: 
    bool rotate(string A, string B, int j){
        for(int i=0; i<A.size(); i++){
            if(A[i] != B[(i+j)%B.size()]){
                return false;
            }
        }
        return true;
    }
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        if(s.size() == 0) return true;

        for(int i=0; i<s.size(); i++){
            if(rotate(s, goal, i)){
                return true;
            }
        }

        return false;
    }
};