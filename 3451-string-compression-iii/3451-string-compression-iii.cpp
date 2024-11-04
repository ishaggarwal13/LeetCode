class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int count = 1;
        int n = word.size();
        char ch = word[0];
        for(int i=1; i<n; i++){
            if(word[i] == ch && count < 9) count++;
            else {
                comp += (to_string(count));
                comp.push_back(ch);
                ch = word[i];
                count = 1;
            }
        }
        comp += (to_string(count));
        comp.push_back(ch);

        return comp;
    }
};