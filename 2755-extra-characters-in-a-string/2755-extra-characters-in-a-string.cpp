class Solution {
public:
    int minExtraChar(const string &s, vector<string>& dictionary) {
        int const n = s.size();
        std::vector<int> dp(n+1);

        for(int i = 1; i < n+1; ++i) {
            dp[i] = dp[i-1] + 1;
            for(std::string const &word: dictionary) {
                int const m = word.length();
                if(i >= m) {
                    bool flag = true;
                    for(int j = i-m; j < i; ++j) {
                        if(s[j] != word[j-i+m]) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) { dp[i] = std::min(dp[i], dp[i-m]); }
                }
            }
        }
        return dp[n];
    }
};