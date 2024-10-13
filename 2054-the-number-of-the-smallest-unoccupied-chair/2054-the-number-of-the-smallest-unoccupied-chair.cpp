class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            occChair;
        priority_queue<int, vector<int>, greater<int>> freeChair;

        int tar = times[targetFriend][0];
        sort(times.begin(), times.end());

        int chair = 0;

        for (int i = 0; i < n; i++) {
            int arr = times[i][0];
            int dep = times[i][1];

            while (!occChair.empty() && occChair.top().first <= arr) {
                freeChair.push(occChair.top().second);
                occChair.pop();
            }

            if (freeChair.empty()) {
                occChair.push({dep, chair});
                if (arr == tar) {
                    return chair;
                }
                chair++;
            } else {
                int minChair = freeChair.top();
                freeChair.pop();
                if (arr == tar) {
                    return minChair;
                }
                occChair.push({dep, minChair});
            }
        }
        return -1;
    }
};