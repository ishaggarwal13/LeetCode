class Solution {
public:
    bool isPalindrome(string s) {
        //stack
        stack<char> st;
        for(char c : s){
            if(isalnum(c)) {
                st.push(tolower(c));
            }
        }

        for(char c : s){
            if(isalnum(c)){
                if(tolower(c) != st.top()) return false;
                st.pop();
            }
        }
        return true;
    }
};