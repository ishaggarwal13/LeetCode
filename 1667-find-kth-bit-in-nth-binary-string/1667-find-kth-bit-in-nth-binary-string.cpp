class Solution {
public:
    char findKthBit(int n, int k) {
        // if n == 1 then return 0
        // find length of the string whihc will form from n
        // if k is the middle index then return 1
        // if k is on left side, recursively find kth bit in s_(n-1)
        // if k is on right side , recusively find the reserve(inverted(s_(n-1)))

        // Base case: When n = 1, the binary string is "0"
        if (n == 1) return '0';
        
        // Find the length of the current string Sn, which is 2^n - 1
        int length = (1 << n) - 1;
        
        // Find the middle position
        int mid = length / 2 + 1;
        
        // If k is the middle position, return '1'
        if (k == mid) return '1';
        
        // If k is in the first half, find the bit in Sn-1
        if (k < mid) return findKthBit(n - 1, k);
        
        // If k is in the second half, find the bit in Sn-1 and invert it
        return findKthBit(n - 1, length - k + 1) == '0' ? '1' : '0';
    }
};