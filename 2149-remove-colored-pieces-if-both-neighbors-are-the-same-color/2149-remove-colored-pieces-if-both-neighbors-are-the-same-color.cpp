class Solution {
public:
    bool winnerOfGame(string colors) {
        if(colors.size() == 1 || colors.size() == 2) return false;
        int alice=0, bob=0;
        
        for(int i=1; i<colors.size()-1; i++){ //not taking first and last element
            if(colors[i] == 'A' && colors[i+1] == 'A' && colors[i-1] == 'A'){
                alice++;
            }
            else if(colors[i] == 'B' && colors[i+1] == 'B' && colors[i-1] == 'B'){
                bob++;
            }
        }
        if(alice>bob) return true;
        return false;
    }
};