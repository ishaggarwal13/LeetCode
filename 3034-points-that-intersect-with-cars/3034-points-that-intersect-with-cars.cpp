class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        set<int> points;
        for(const vector<int>& num : nums){
            for(int i = num[0]; i<= num[1]; i++){
                points.insert(i);
            }
        }
        return points.size();
    }
};