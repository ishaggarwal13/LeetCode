class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> arr;
        //CONVERT TIME STAMP INTO MINUTES
        for(auto time : timePoints){
            int hr = stoi(time.substr(0,2));
            int min = stoi(time.substr(3,2));
            int minutes = hr*60 + min;
            arr.push_back(minutes);
        }
        sort(arr.begin(), arr.end());

        int mini = INT_MAX;
        for(int i=1; i<arr.size(); i++){
            mini = min(mini, arr[i] - arr[i-1]);
        }

        return min(mini, abs(arr[0] + 1440 - arr[arr.size()-1]));
    }
};