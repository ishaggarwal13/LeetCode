class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> arr;
        //CONVERT TIME STAMP INTO MINUTES
        for(auto time : timePoints){
            string s = time;
            int hr=0, min=0, i=0;
            //extract hours
            while(s[i] != ':'){
                hr = hr*10 + (s[i] - '0');
                i++;
            }
            i++;
            while(i<s.size()){
                min = min*10 + (s[i] - '0');
                i++;
            }
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