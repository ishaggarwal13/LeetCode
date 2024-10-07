class Solution {
public:
    int minLength(string s) {
        if(s.length() == 1) return 1;

        stack<char> st;
        for(auto c : s){
            if(!st.empty()){
                if(c == 'B' && st.top() == 'A'){
                st.pop();
                continue;
            }
            else if(c == 'D' && st.top() == 'C'){
                st.pop();
                continue;
            }
            }
                st.push(c);
        }

        string t = "";
        while(!st.empty()){
            char x = st.top();
            t += x;
            st.pop();
        }

        return t.length();
    }
};