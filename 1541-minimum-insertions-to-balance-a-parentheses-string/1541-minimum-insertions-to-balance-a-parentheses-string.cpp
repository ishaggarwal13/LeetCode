class Solution {
public:
    //o(n) & o(1)
    int minInsertions(string s) {
        int ans = 0, close = 0;
        for(char st : s){
            if(st == '('){
                if(close % 2 == 1) ans++, close++;
                else close+=2; // need two )) for (
            } else {
                if(close == 0) ans++, close = 1; //only ) close needed ans++
                else close--;
            }
        }
        return ans + close;
    }
};