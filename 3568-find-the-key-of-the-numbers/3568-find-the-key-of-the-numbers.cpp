class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int s1 = num1%10, s2 = num2%10, s3 = num3%10;
        num1 = num1/10;
        num2 = num2/10;
        num3 = num3/10;
        int f1 = num1%10, f2 = num2%10, f3 = num3%10;
        num1 = num1/10;
        num2 = num2/10;
        num3 = num3/10;
        int e1 = num1%10, e2 = num2%10, e3 = num3%10;
        num1 = num1/10;
        num2 = num2/10;
        num3 = num3/10;
        int res = min(s1, min(s2,s3))*1 + min(f1, min(f2,f3))*10 + min(e1, min(e2,e3))*100
                    + min(num1, min(num2,num3))*1000;
        return res;
    }
};