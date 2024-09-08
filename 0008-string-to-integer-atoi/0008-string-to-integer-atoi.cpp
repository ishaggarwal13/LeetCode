class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int sign = 1;
        double num = 0;

        int i=0;
        while(i<n && s[i] == ' '){ //white space
            i++;
        }

        if(s[i] == '-'){
            sign = -1;
            i++;
        } else if(s[i] == '+'){
            i++;
        }

        while(i<n && s[i] >= '0' && s[i] <= '9'){
            num = num*10 + (s[i] - '0'); //extracting the digit
            if(num > INT_MAX && sign == -1){
                return INT_MIN;
            } else if(num > INT_MAX && sign == 1){
                return INT_MAX;
            }
            i++;
        }

        if(sign == -1){
            return num*sign;
        }

        return (num*sign);
    }
};