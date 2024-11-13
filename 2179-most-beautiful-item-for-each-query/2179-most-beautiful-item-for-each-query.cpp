struct Item {
    int price;
    int beauty;

    bool operator<(const Item& other) const {
        return price < other.price;
    }
};

struct Query {
    int threshold;
    int index;

    bool operator<(const Query& other) const {
        return threshold < other.threshold;
    }
};

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<Item> all;
        for (const vector<int>& item : items) {
            all.push_back({.price = item[0], .beauty = item[1]});
        }
        sort(all.begin(), all.end());

        vector<Query> qs;
        for (int i = 0; i < queries.size(); ++i) {
            qs.push_back({.threshold = queries[i], .index = i});
        }
        sort(qs.begin(), qs.end());

        vector<int> answer(queries.size());
        int index = 0;  // index through the `all` array.
        int max_beauty = 0;
        for (const Query& q : qs) {
            while (index < all.size() && all[index].price <= q.threshold) {
                max_beauty = max(max_beauty, all[index].beauty);
                ++index;
            }
            answer[q.index] = max_beauty;
        }
        return answer;
    }
};