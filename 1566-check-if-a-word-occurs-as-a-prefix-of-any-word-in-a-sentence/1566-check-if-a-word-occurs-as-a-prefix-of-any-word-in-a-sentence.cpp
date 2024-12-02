class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream ss(sentence);
        string word;
        int index = 1;
        while(ss >> word){
            if(word.length() >= searchWord.length() &&
            word.substr(0, searchWord.length()) == searchWord){
                return index;
            }
            index++;
        }
        return -1;
    }
};