class Solution {
public:
    string convert(int num){
        if(num == 1) return "1";
        string ans = "";
        while(num){
            ans = to_string(num%2) + ans;
            num /= 2;
        }
        return ans;
    }
    string convertDateToBinary(string date) {
        string year = convert(stoi(date.substr(0, 4)));
        string mon = convert(stoi(date.substr(5, 2)));
        string d = convert(stoi(date.substr(8, 2)));

        return year + "-" + mon + "-" + d;
    }
};