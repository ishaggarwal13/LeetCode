class Solution {
public:
    int findComplement(int num) {
        //using bitmasking
        //O(logn) & O(1)
        unsigned mask = ~0;
        while(mask & num) mask = mask << 1;
        return ~num ^ mask;
    }
};