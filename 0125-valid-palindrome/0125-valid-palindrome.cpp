class Solution {
public:
    bool isPalindrome(string s) {
        // two pointer but first converting into full numeric both captital and small
        string filter = "";
        for(auto c : s){
            if(isalnum(c)) filter += c;
        }

        int i = 0;
        int j = filter.size()-1;
        while(i<j){
            if(tolower(filter[i]) != tolower(filter[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};