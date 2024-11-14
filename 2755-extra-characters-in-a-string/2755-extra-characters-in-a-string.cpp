class Solution {
public:
    int dp[100];
    int solve(string &s, vector<string> &dict, int ptr){
        
        if(ptr >= s.size()) return 0;
        if(dp[ptr]!=-1) return dp[ptr];
        // now you can either a single character equal to s[ptr] and get ans from rest 
        int easyWay = 1 + solve(s,dict,ptr+1);
        int tougherWay = INT_MAX; // it involves use one of the words from dict
        for(auto &x : dict){
            // check if remaining chars are compatible first
            bool right = true;
            for(int i = 0; i<x.size();++i){
                if(ptr + x.size()  > s.size() || x[i] != s[ptr+i]) {right = false; break;}
            }
            if(!right) continue;
            tougherWay = min(tougherWay,solve(s,dict,ptr+x.size()));
        }
        return dp[ptr] = min(easyWay,tougherWay);
    }
    int minExtraChar(string s, vector<string>& dict) {
        for(int i = 80; i>=0;--i) dp[i] = -1;
        return solve(s,dict,0);
    }
};