class Solution {
public:
    double recursion(double x, long nn){
        if(nn == 0) return 1;
        double temp = recursion(x, nn/2);

        if(nn % 2 == 0) return temp * temp;

        return x * temp * temp;
    }
    double myPow(double x, int n) {
        long nn = n;
        double ans = recursion(x, nn);
        return n<0 ? 1/ans : ans;
    }
};