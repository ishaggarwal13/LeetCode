class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n =  nums.size();
        vector<int> result(n-k+1, -1);
        int score = 0;

        for(int i=0; i<n; i++){
            if(i && nums[i-1] + 1 == nums[i]){
                score++;
            } else {
                score = 0;
            }
            if(score >= k-1){
                result[i-k+1] = nums[i];
            }
        }
        return result;
    }
};