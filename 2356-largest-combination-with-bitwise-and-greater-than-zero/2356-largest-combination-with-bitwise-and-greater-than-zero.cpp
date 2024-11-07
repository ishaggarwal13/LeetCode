class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int>bits(32,0);
        int j = 0;
        for(auto &i:candidates){
            j = 0;
            bits[0] += (i&1);
            i = i>>1;
            j++;
            while(i){
                
                
                bits[j] += i&1;
                j++;
                i = i>>1;

            }
            

            
        }

        int ans = bits[0];
        for( int i = 1; i<32; i++){
            if(bits[i]>ans){
                ans = bits[i];
            }
        }
        return ans;
    }
};