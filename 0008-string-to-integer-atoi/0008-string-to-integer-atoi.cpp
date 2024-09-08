class Solution {
public:
    int myAtoi(string s) {
        int len = s.size();
        double num = 0;

        int i=0;
        while(s[i] == ' '){ //white space
            i++;
        }

        bool pos = s[i] == '+';
        bool neg = s[i] == '-';
        pos == true ? i++ : i;
        neg == true ? i++ : i;

        while(i<len && s[i] >= '0' && s[i] <= '9'){
            num = num*10 + (s[i] - '0'); //extracting the digit
            i++;
        }

        num = neg ? -num : num;

        //edge condition of 32-bit int
        num = (num > INT_MAX) ? INT_MAX : num;
        num = (num < INT_MIN) ? INT_MIN : num;

        return int(num);
    }
};