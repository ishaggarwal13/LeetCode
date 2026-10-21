class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        string ans = s;

        sort(ans.begin(), ans.end());

        if (s == ans) return 0;
        if (n == 2) return -1;

        char mini = *min_element(s.begin(), s.end());
        char maxi = *max_element(s.begin(), s.end());

        int idx1 = s.find(mini);
        int idx2 = s.rfind(maxi);

        if (s[0] == mini || s[n - 1] == maxi) return 1;
        else if (idx1 != n - 1 || idx2 != 0) return 2;
        else return 3;
    }
};