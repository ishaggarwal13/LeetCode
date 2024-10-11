class Solution {
string getValue(string s) {
        int sum = 0, val;
        
        for(auto ch : s) {
            val = ch - '0';
            sum += val;
        }

        return to_string(sum);
    }

public:
    int getLucky(string s, int k) {
        string temp = "";

        for(int i = 0; i < s.length(); i++) {
            temp += to_string(s[i] - 'a' + 1);
        }

        while(k--){
            temp = getValue(temp);
        }

        return stoi(temp);
    }
};