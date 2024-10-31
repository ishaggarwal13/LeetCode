class Solution {
public:
    int solve(string num, int k) {
        if(k==0) return stoi(num);
        int s = 0;
        for(int i=0; i<num.length(); i++) {
            s += (int)(num[i]-'1'+1);
        }
        return solve(to_string(s), k-1);
    }

    int getLucky(string s, int k) {
        string num;
        for(int i=0; i<s.length(); i++) {
            num += to_string((int)(s[i]-'a'+1));
        }
        return solve(num, k);
    }
};