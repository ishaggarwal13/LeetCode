class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 1) return false;
        int sum = 1; // as 1 is divisor of every number
        for(int i=2; i<= num/i; i++){
            if(num % i == 0) {
                sum += i;

                if(i != num/i){
                    sum += num/i;
                }
            }
        }
        return sum == num;
    }
};