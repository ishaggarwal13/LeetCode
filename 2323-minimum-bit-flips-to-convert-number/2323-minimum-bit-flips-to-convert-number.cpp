class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        
        //xor will change the bit to 1 which is different in both start and goal
        int num = start ^ goal; 

        //Now we can count the 1's bit in num by using & 1 to check last bit 
        //and >> right shift to process the next bit

        while(num){
            count += num & 1; //if last bit is 1

            num >>=1; //right shift to check next bit
        }
        return count;
    }
};