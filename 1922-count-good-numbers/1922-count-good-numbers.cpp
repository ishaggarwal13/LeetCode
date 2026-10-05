class Solution {
public:
    long mod = 1e9+7;

    long power(long base, long expo, long mod){
        long ans = 1;
        while(expo > 0){
            if(expo % 2 == 0){
                base = (base * base)% mod;
                expo = expo/2;
            } else {
                ans = (ans * base) % mod;
                expo = expo - 1;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        if(n==1) return 5;
        long even = (n+1)/2;
        long odd = n/2;

        long evenWays = power(5, even, mod);
        long oddWays = power(4, odd, mod);

        return (int)((evenWays * oddWays) % mod);
    }
};