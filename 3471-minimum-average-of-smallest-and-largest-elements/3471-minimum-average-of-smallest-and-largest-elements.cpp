class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i=0, j=n-1;
        double ans = 1000;
        while(i<j){
            double k = (nums[i] + nums[j]) / (2*1.0);
            ans = min(ans, k);
            i++;
            j--;
        }
        return ans;
    }
};