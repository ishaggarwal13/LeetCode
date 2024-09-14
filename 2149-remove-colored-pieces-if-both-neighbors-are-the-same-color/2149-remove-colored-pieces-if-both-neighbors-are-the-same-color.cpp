class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice=0, bob=0;
        
        for(int i=1; i<colors.size()-1; i++){ //not taking first and last element
            char curr = colors[i];
            char prev = colors[i-1];
            char next = colors[i+1];

            if(curr == 'A' && prev == 'A' && next == 'A'){
                alice++;
            }
            else if(curr == 'B' && prev == 'B' && next == 'B'){
                bob++;
            }
        }
        return alice>bob;
    }
};