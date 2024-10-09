class Solution {
public:
    int minLength(string s) {
        int idx = 0; //act like stack pointer
        for(char ch : s){
            if(idx>0 && 
            ((s[idx - 1] == 'A' && ch == 'B') || 
            (s[idx - 1] == 'C' && ch == 'D'))) {
                idx--;
            } else {
                s[idx++] = ch;
            }
        }
        return idx;
    }
};