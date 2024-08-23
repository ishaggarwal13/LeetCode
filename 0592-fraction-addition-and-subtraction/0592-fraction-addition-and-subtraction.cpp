class Solution {
public:
    //O(n) and O(1)
    string fractionAddition(string expression) {
        int numerator=0, denominator=1; //intially 0/1 
        int i=0, n=expression.size();

        while(i<n){
            int sign = 1;
            if(expression[i] == '-' || expression[i] == '+' ){
                if(expression[i] == '-') sign = -1;
                i++;
            }

            int num=0;
            while(i<n && isdigit(expression[i])){
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            num *= sign;

            i++; //skip / chracter

            int den=0;
            while(i<n && isdigit(expression[i])){
                den = den * 10 + (expression[i] - '0');
                i++;
            }

            numerator = den*numerator + num*denominator;
            denominator = den * denominator;

            int gcdval = gcd(abs(numerator), denominator);
            numerator /= gcdval;
            denominator /= gcdval;
        }
        return to_string(numerator) + "/" + to_string(denominator);
    }
};