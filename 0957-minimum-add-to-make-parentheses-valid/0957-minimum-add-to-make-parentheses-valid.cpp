class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        stack<int> st;
        for(char ch : s){
            if(ch == ')'){
                if(st.empty())
                    count++;
                else if(st.top() == '(')
                    st.pop();
                else 
                    st.push(ch);
            } else if(ch == '('){
                st.push(ch);
            }
        }
        return count+st.size();
    }
};