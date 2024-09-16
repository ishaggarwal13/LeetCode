class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int time = 0;
        for(int i=0; i<timeSeries.size()-1; i++){ //start to end-1
            int timediff = timeSeries[i+1] - timeSeries[i];
            time += (timediff < duration) ? (timediff) : (duration);
        }
        time += duration;
        return time;
    }
};