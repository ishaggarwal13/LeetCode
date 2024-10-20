class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(char c : expression){
            if(c == ',' || c == '(')
                continue;
            if(c == '&' || c == '|' || c == '!' || 
                c == 'f' || c == 't'){
                st.push(c);
            } else if(c == ')'){
                bool hastrue = false , hasfalse = false;

                while(st.top() != '!' && st.top() != '&' && st.top() != '|'){
                    char topval = st.top();
                    st.pop();
                    if(topval == 'f') hasfalse = true;
                    if(topval == 't') hastrue = true;
                }
                char op = st.top();
                st.pop();
                if(op == '!'){
                    st.push(hastrue ? 'f' : 't');
                } else if (op == '&'){
                    st.push(hasfalse ? 'f' : 't');
                } else {
                    st.push(hastrue ? 't' : 'f');
                }
            }
        }
        return st.top() == 't';
    }
};