class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for(char w : word){
            freq[w]++;
        }

        vector<int> frequencies;
        for(auto& pair: freq){
            frequencies.push_back(pair.second);
        }

        sort(frequencies.begin(), frequencies.end());

        int minDeletions = INT_MAX;
        int n = frequencies.size();
        
        for (int i = 0; i < n; ++i) {
            int base = frequencies[i];
            int totalDeletions = 0;

            for (int j = 0; j < i; ++j) {
                totalDeletions += frequencies[j];
            }
            
            for (int j = i; j < n; ++j) {
                if (frequencies[j] > base + k) {
                    totalDeletions += frequencies[j] - (base + k);
                }
            }
            
            if (totalDeletions < minDeletions) {
                minDeletions = totalDeletions;
            }
        }
        return minDeletions;
    }
};