class Solution {
public:
    static bool compare(const vector<int>& p, const vector<int>& q){
        return p[1] > q[1]; //dec sorting
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int ans = 0;
        for(const auto& box : boxTypes){
            int boxes = box[0];
            int units = box[1];
            if(truckSize >= boxes){
                ans += (boxes*units);
                truckSize -= boxes;
            } else {
                ans += (truckSize*units);
                truckSize = 0;
                break;
            }
        }
        return ans;
    }
};