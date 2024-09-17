class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it : p){
            pq.push(it);
        }
        int ans=0, i=0;
        sort(t.begin(), t.end());
        while(!pq.empty() && i < t.size()){
            if(t[i] >= pq.top()){
                pq.pop();
                ans++;
            }
            i++;
        }
        return ans;
    }
};