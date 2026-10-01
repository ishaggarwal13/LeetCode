#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    // Time : O(n), Space : O(n)
    bool isValid(string s) {
        stack<char> st;

        for(char ch : s){
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                st.pop();
                if(ch == ')' && top != '(') return false;
                if(ch == ']' && top != '[') return false;
                if(ch == '}' && top != '{') return false;
            }
        }
        return st.empty();
    }
};