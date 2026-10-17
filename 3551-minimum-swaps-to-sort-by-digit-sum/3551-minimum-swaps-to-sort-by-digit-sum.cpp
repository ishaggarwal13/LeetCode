class Solution {
public:
    int digitSum(int num){
        int sum = 0;

        while(num > 0){
            sum += num%10;
            num /= 10;
        }

        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> target = nums;

        sort(target.begin(), target.end(),
        [&](int a, int b) {
            int sumA = digitSum(a);
            int sumB = digitSum(b);

            if(sumA != sumB)
                return sumA < sumB;
            
            return a < b;
        });

        unordered_map<int, int> correctPos;

        for(int i = 0; i < n; i++) {
            correctPos[target[i]] = i;
        }

        vector<bool> visited(n, false);

        int swaps = 0;

        for(int i = 0; i < n; i++) {
            if(visited[i])
                continue;

            int j = i;
            int cycleSize = 0;

            // Follow the cycle
            while(!visited[j]) {
                visited[j] = true;
                j = correctPos[nums[j]];
                cycleSize++;
            }

            // Cycle of length k needs k-1 swaps
            swaps += cycleSize - 1;
        }

        return swaps;
    }
};