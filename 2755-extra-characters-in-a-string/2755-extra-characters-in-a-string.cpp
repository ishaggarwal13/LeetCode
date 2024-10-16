class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<pair<int, int>> seq;
        for (const auto& word: dictionary) {
            int pos = -1, n = word.size();
            do {
                pos = s.find(word, pos + 1);
                if (pos >= 0) seq.push_back(pair<int, int>(pos, pos + n));
            } while(pos != string::npos);
        }
        int n = s.size(), m = seq.size();
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = i ? min(dp[i - 1] + 1, i + 1) : 1;
            for (int j = 0; j < m; ++j) {
                if (seq[j].second - 1 == i) {
                    int front = seq[j].first - 1;
                    dp[i] = front >= 0 ? min(dp[i], dp[front]) : 0;
                }
            }
        }
        return dp[n - 1];
    }
};