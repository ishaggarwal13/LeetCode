class Solution {
public:
    int minSwaps(string s) {
        int count = 0;
        int moves = 0;
        for(char ch : s){
            if(ch == ']') {
                if(count == 0){
                    count++;
                    moves++;
                } else {
                    count--;
                }
            } else count++;
        }
        return moves;
    }
};