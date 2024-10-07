class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string a1 = to_string(num1);
        string a2 = to_string(num2);
        string a3 = to_string(num3);

        vector<char> out;
        vector<string> ans(3);
        ans[0] = a1;
        ans[1] = a2;
        ans[2] = a3;
        for (int i = 0; i < ans.size(); i++) {
            while (ans[i].size() < 4) {
                ans[i] = '0' + ans[i];
            }
        }
        int j = 0;
        while (j < 4) {
            char u = min({ans[0][j], ans[1][j], ans[2][j]});
            out.push_back(u);
            j++;
        }
        string key(out.begin(), out.end());
        return stoi(key);
    }
};