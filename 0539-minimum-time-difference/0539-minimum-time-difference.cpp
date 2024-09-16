class Solution {
public:
    int minutes(string time) {
        return ( ((((time[0] - '0')*10) + (time[1] - '0')) * 60) + (((time[3] - '0')*10) + (time[4] - '0')) );
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> arr;
        //CONVERT TIME STAMP INTO MINUTES
        for(auto time : timePoints){
            arr.push_back(minutes(time));
        }
        sort(arr.begin(), arr.end());

        int mini = INT_MAX;
        for(int i=1; i<arr.size(); i++){
            mini = min(mini, arr[i] - arr[i-1]);
        }

        return min(mini, abs(arr[0] + 1440 - arr[arr.size()-1]));
    }
};