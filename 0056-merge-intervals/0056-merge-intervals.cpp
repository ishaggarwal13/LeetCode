class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort the array in asec order
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(auto interval : intervals){
            //if arr is emoty tehn insert first vector and after that
            //compare the last element of vector with curr first element is it is greater then add
            if(ans.empty() || ans.back()[1] < interval[0]){
                ans.push_back(interval);
            } else{ //otherwise update second element in the vector
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }
        return ans;
    }
};