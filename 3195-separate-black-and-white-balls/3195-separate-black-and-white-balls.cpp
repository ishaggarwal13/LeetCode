class Solution {
public:
    long long minimumSteps(string s) {
        // count the black balls 1 
        // every time encounter white 0 , can be swap opp
        // total no of swaps == sum of the swap opp
        int black=0;
        long long  swap=0;
        for(char c: s){
            (c=='1')?black++:swap+=black;
        }
        return swap;
    }
};