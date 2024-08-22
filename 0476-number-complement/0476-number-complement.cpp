class Solution {
public:
    int findComplement(int num) {
        if(num == 0) return 1;
        int ans=0;
        int i=0;
        while(num){
            if(num%2 == 0) 
                ans += pow(2, i);
            i++;
            num /= 2;
        }
        return ans;
    }
};