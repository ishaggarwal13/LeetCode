class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        if(n==0) return 0;
        int time = 0;
        for(int i=0; i<n-1; i++){ //start to end-1
            if(timeSeries[i] + duration <= timeSeries[i+1]) time += duration;
            else time += timeSeries[i+1] - timeSeries[i];
        }
        time += duration;
        return time;
    }
};