class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Min heap for getting the minimum element value of the range
        // Custom comparator: compare based on the first element in the vector
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0]; // this ensures we get the smallest element first (min-heap)
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

        int k = nums.size(); // number of lists
        int maxval = INT_MIN; // for tracking the maximum value of the current range

        // Pushing the first element of each list into the min-heap
        for(int i = 0; i < k; i++){
            pq.push({nums[i][0], i, 0}); // push the first element of each list with its list number and index
            maxval = max(maxval, nums[i][0]); // update the maximum value
        }

        int start = 0, end = INT_MAX; // to store the smallest range

        // Processing the heap
        while(!pq.empty()){
            auto curr = pq.top(); // store the top of the min-heap (smallest element)
            pq.pop(); // remove it from the heap
            int minval = curr[0]; // the smallest value
            int row = curr[1]; // list (row) it came from
            int index = curr[2]; // the index within that list

            // Update the range if the current range is smaller than the previous one
            if(maxval - minval < end - start){
                start = minval;
                end = maxval;
            }

            // If the current row is exhausted, we cannot move further
            if(index + 1 == nums[row].size()){
                break;
            }

            // Push the next element from the same row into the heap
            int nextval = nums[row][index + 1];
            pq.push({nextval, row, index + 1});

            // Update the maximum value if necessary
            maxval = max(maxval, nextval);
        }
        return {start, end}; // return the smallest range found
    }
};