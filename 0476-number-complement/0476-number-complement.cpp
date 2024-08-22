class Solution {
public:
    int findComplement(int num) {
        //using bitmasking
        //O(1) & O(1)
        if(num==0) return 1;
        unsigned int mask = ~0; //~bitwise not operator
        while(num & mask){ //bitwise and operator is both bits are 1 then result is 1
            mask<<=1;
        }
        return ~mask ^ num;
        
    }
};