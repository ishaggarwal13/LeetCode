class Solution {
public:
    int countPrimes(int n) {
        //Sieve of Eratosthenes
        //Time complexity: O(nloglogn) Space complexity: O(n)
        if(n < 2) return false;
        int count = 0;
        //suppose every number is prime
        vector<bool> prime(n, true);
        //setting 0 and 1 as false
        prime[0] = prime[1] = false; 
        for(int i=2; i<n; i++){
            if(prime[i]){
                count++;
                //now making every multiple of 1 as false
                for(int j = i*2; j<n; j+=i){
                    prime[j] = false;
                }
            }
        }
        return count;
    }
};