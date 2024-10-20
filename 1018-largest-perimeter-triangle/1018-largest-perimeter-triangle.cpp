class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // sort side length in descending order
        std::sort( nums.rbegin(), nums.rend() );
        
        for( int i = 0 ; i < nums.size()-2 ; i++ ){
            
            // Accept: find the triangle with largest perimeter
            if( nums[i] < ( nums[i+1] + nums[i+2]) ){
                return nums[i] + nums[i+1] + nums[i+2];
            }
            
        }
        
        // Reject: impossible to make triangle
        return 0;
    }
};