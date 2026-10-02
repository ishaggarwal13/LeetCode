#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(string& current, int open, int close, int n, vector<string>& ans){
        if(open == n && close == n){
            ans.push_back(current);
            return;
        }

        if(open < n){
            current += '(';
            backtrack(current, open + 1, close, n, ans);
            current.pop_back();
        }

        if(close < open){
            current += ')';
            backtrack(current, open, close + 1, n, ans);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = 0;
        int close = 0;
        string current = "";

        backtrack(current, open, close, n, ans);

        return ans;
    }
};