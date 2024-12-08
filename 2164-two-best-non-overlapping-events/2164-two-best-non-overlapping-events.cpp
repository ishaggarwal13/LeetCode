class Solution {
public:
    using info=tuple<int, bool, int>;
    int maxTwoEvents(vector<vector<int>>& events) {
        const int n=events.size();
        vector<info> time(n*2);
        for(int i=0; i<n; i++){
            int s=events[i][0], e=events[i][1], v=events[i][2];
            time[2*i]={s, 1, v};
            time[2*i+1]={e+1, 0, v};
        }
        sort(time.begin(), time.end());
        int ans=0, maxV=0, n2=n*2;
        for(auto& [t, isStart, v]: time){
            if (isStart) ans=max(ans, maxV+v);
            else maxV=max(maxV, v);
        }
        return ans;    
    }
};