class Solution {
public:
    bool canJump(vector<int>& nums) {
        //O(N) & O(1)
        int maxIndex=0;
        for(int i=0; i<nums.size(); i++){ // 2,3,1,1,4
            if(i>maxIndex) return false;
            //we can maximum jump upto i+arr[i]
            maxIndex = max(maxIndex, i+nums[i]); // 0+2=2, 3+1=4, 1+2=3/max4, 1+3=4/4
        }
        return true;
    }
};