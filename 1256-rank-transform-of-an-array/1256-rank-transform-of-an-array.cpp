#include <execution>
class Solution {
public:
    constexpr inline vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) {
            return {};
        }
        const int n = arr.size();
        vector<pair<int, int>> result(n);        
        transform(
            arr.begin(), arr.end(), result.begin(),
            [i = 0](int value) mutable { return make_pair(value, i++); });
        sort(execution::par_unseq,
            result.begin(), result.end(),
            [](const pair<int, int>& p1, const pair<int, int>& p2){
                return p1.first < p2.first;
            });
        int rank = 1;
        for (int i = 0; i < n - 1; ++i) {
            arr[result[i].second] = rank;
            if (result[i].first != result[i + 1].first) {
                ++rank;
            }
        }
        arr[result.back().second] = rank;
        return arr;        
    }
};