class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mod_count = vector<int>(k, 0);
        for (int i = 0; i < arr.size(); i++) {
            // Be careful about negative values.
            mod_count[(arr[i] % k + k) % k]++;
        }
        if (mod_count[0] % 2 == 1) {
            return false;
        }
        for (int i = 1; i <= k / 2; i++) {
            if (i + i == k) {
                if (mod_count[i] % 2 == 1) {
                    return false;
                }
            } else {
                if (mod_count[i] != mod_count[k - i]) {
                    return false;
                }
            }
        }
        return true;
    }
};