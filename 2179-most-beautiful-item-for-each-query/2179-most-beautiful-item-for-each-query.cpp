class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int itemsLen = items.size();
        int queriesLen = queries.size();

        map<int, int> beautyMap;

        int i = 0;
        std::map<int, int>::iterator it;

        for (; i < itemsLen; ++i) {
            it = beautyMap.upper_bound(items[i][0]);
            it = (it != beautyMap.begin()) ? --it : it;
            if (it->first > items[i][0] || it->second < items[i][1]) {
                beautyMap[items[i][0]] = items[i][1];

                for (it = std::next(beautyMap.begin()); it != beautyMap.end(); ++it) {
                    if (std::prev(it)->second > it->second)
                        it->second = std::prev(it)->second;
                }
            }
        }

        for (i = 0; i < queriesLen; ++i) {
            if (queries[i] < beautyMap.begin()->first) queries[i] = 0;
            else {
                it = beautyMap.upper_bound(queries[i]);
                --it;
                queries[i] = it->second;
            }
        }

        return queries;
    }
};