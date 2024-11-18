class Solution {
public:
    void rotateByOne(vector<int> &nums){
		int n = nums.size(), temp = nums[n-1];
		for(int i=n-1; i>0; i--){
			nums[i] = nums[i-1];
		}
        nums[0] = temp;
	}
    void rotate(vector<int>& nums, int k) {
        for(int i=0; i<k; i++) rotateByOne(nums);
    }
};