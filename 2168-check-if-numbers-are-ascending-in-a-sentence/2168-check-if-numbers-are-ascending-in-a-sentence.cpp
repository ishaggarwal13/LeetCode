class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = -1;
        int curr = -1;
        string temp = "";
        s += "";

        for(int i=0; i<=s.size(); i++){
            if(isdigit(s[i])){
                temp = temp + s[i];
            } else if(temp.size()){
                curr = stoi(temp); //storing the integer into curr
                if(prev >= curr) return false; //checking asec condn
                prev = curr; //if not then setting prev to curr
                temp = ""; //set back to empty string
            }
        }
        
        return true;
    }
};