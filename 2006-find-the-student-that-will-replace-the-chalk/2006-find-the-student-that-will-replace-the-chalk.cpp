class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = accumulate(chalk.begin(), chalk.end(), 0ll);

        k %= sum;

        for(int i=0; i<chalk.size(); i++){
            if(chalk[i]>k){
                return i;
            } else {
                k -= chalk[i];
            }
        }
        return 0;
    }
};