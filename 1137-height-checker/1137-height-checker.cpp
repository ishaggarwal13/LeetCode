class Solution {
public:
    int heightChecker(vector<int>& heights) {
       vector<int> expected(heights);
        int n = expected.size();
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < n - 1 - i; j++) {
                if(expected[j] > expected[j + 1]) {
                    int temp = expected[j];
                    expected[j] = expected[j + 1];
                    expected[j + 1] = temp;
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(heights[i] != expected[i]) {
                ans++;
            }
        }
        
        return ans;
    }
};