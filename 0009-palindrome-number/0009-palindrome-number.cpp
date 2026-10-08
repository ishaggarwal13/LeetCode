class Solution {
public:
    bool isPalindrome(int x) {
        //reverse number 
        long long rev = 0;
        int temp = x;
        while(temp>0){
            rev = rev*10 + temp%10;
            temp = temp/10;
        }

        if(x == rev) return true;
        else return false;
    }
};