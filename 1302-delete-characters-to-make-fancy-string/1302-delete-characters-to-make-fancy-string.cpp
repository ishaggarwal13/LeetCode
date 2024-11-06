class Solution {
public:
    string makeFancyString(string s) {
        if(s.size() < 3) return s;

        int j = 2; // pointer points to third element
        for(int i=2; i<s.size(); i++){ 
            //apply condition to check if all three are equal nothg will happen
            // but not then at j pointer string will shift to left and move j++
            if(s[i] != s[j-1] || s[i] != s[j-2]){
                s[j] = s[i];
                j++;
            }
        }
        s.resize(j);
        return s;
    }
};