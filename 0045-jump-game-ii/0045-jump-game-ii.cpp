class Solution {
public:
    int jump(vector<int>& nums) {
        //Greedy - choosing range after taking x jump till farthest we can go 
        //O(n) TC and O(1) SC
        int n = nums.size();
        int jumps=0, l=0, r=0;
        while(r < n-1){
            int farthest = 0;
            for(int i = l; i<=r; i++){ //range of l->r 
                farthest = max(farthest, i+nums[i]);
            }
            l = r+1;
            r = farthest; //(r is the farthest jump)
            jumps++;
        }
        return jumps;
        
    }
};