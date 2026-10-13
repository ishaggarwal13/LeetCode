class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int curr1 = 0;
        int curr2 = 1;
        for(int i=2; i<=n; i++){
            int curr = curr1 + curr2;
            curr1 = curr2;
            curr2 = curr;
        }
        return curr2;
    }
};