class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ret = 0;
        int prev = 0;
        int sum = 0;
        int il = banned.size();
        sort(banned.begin(), banned.end());
        for (int i = 0; i < il; i++) {
            if (sum < maxSum && n > prev) {
                int mn = min(banned[i] - 1, n);
                int cnt = mn-prev;
                if (cnt > 0) {
                    //cout << arr[i] << ", cnt: " << cnt << endl;
                    int sum2 = ((prev + 1) * cnt) + (cnt * (cnt - 1)) / 2;
                    while(cnt > 0 && (sum + sum2) > maxSum) {
                        sum2 -= mn;
                        mn--;
                        cnt--;
                    }
                    if (cnt == 0) break;
                    sum += sum2;
                    ret += cnt;
                }
                prev = banned[i];
            } else {
                break;
            }
        }
        if (sum < maxSum && n > prev) {
            int mn = n;
            int cnt = n-prev;
            int sum2 = ((prev + 1) * cnt) + (cnt * (cnt - 1)) / 2;
            while(cnt > 0 && (sum + sum2) > maxSum) {
                sum2 -= mn;
                mn--;
                cnt--;
            }
            ret += cnt;
        }
        return ret;
    }
};