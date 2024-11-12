class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int max_beauty = 0;
        vector<int> prices, beauties;
        sort(items.begin(), items.end());

        for(const auto& item : items){
            int price = item[0];
            int beauty = item[1];
            max_beauty = max(max_beauty, beauty);
            prices.push_back(price);
            beauties.push_back(max_beauty);
        }

        vector<int> results(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
        // Find the rightmost price that is <= queries[i] using binary search
        int idx = upper_bound(prices.begin(), prices.end(), queries[i]) - prices.begin() - 1;
        if (idx >= 0) {
            results[i] = beauties[idx];
        } else {
            results[i] = 0;
        }
    }

    return results;
    }
};