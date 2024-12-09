class Solution {
public:
    int largestCombination(vector<int>& c) {
        int ret = 0;
        vector<int> bs(24);
        for (auto& n : c) {
            int nn = n;
            for (int i = 0; i < bs.size(); i++, nn >>= 1) bs[i] += nn & 1;
        }
        for(auto& b:bs) if(ret < b) ret = b;
        return ret;
    }
};