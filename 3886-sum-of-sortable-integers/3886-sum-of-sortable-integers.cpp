class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        //O(n * d(n))
        int n = nums.size();
        int total = 0;
        for(int k=1; k<=n; k++){
            if(n % k) continue;
            bool ok = true;
            int preMax = 0;
            for(int base=0; base<n; base+=k){
                int desc = 0;
                int mini = nums[base];
                int maxi  = nums[base];
                for(int j=0; j<k; j++){
                    int a = nums[base+j];
                    int b = nums[base+(j+1) % k];
                    if(a > b) desc++;
                    mini = min(mini, a);
                    maxi = max(maxi, a);
                }
                if(desc > 1 || preMax > mini){
                    ok = false;
                    break;
                } 
                preMax = maxi;
            }
            if(ok) total += k;
        }
        return total;
    }
};