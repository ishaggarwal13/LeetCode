class Solution {
public:
    char findKthBit(int n, int k) {
        // if n == 1 then return 0
        // find length of the string whihc will form from n
        // if k is the middle index then return 1
        // if k is on left side, recursively find kth bit in s_(n-1)
        // if k is on right side , recusively find the reserve(inverted(s_(n-1)))

        if(n==1) return '0';
        int len = pow(2, n) - 1;
        int mid = len/2 + 1; //1-based index

        if(k == mid){
            return '1';
        } else if(k < mid){
            return findKthBit(n-1, k);
        } else{
            int mirroredK = mid - (k - mid); 
            // finding index of right half into left half 
            // such as k = 6 then in left half it should be 2
            return findKthBit(n - 1, mirroredK) == '0' ? '1' : '0';
        }
    }
};