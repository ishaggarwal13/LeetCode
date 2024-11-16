class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n-k+1);

        // till n-k because we are taking first element of subarray
        for(int i=0; i<=n-k; i++){
            unordered_set<int> uniqueElements;
            int maxElement = INT_MIN;
            int minElement = INT_MAX;
            bool isSorted = true;

            // till i+k becuase we are incsering the index of window too
            for(int j=i; j<i+k; j++){
                uniqueElements.insert(nums[j]);
                maxElement = max(maxElement, nums[j]);
                minElement = min(minElement, nums[j]);

                if(j > i && nums[j] < nums[j-1]){
                    isSorted = false;
                }
            }

            if(uniqueElements.size() == k && (maxElement - minElement) == (k-1) && isSorted){
                result[i] = maxElement;
            } else {
                result[i] = -1;
            }
        }
        return result;
    }
};