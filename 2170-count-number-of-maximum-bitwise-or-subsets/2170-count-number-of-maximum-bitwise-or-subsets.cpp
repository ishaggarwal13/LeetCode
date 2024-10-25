class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {

        int maximum = std::accumulate(nums.begin(), nums.end(), 0,
                                      [](int a, int b) { return a | b; });

        std::vector<int> ors = {0,nums[0]};
        int also_max_subset = 0;

        if(nums[0] == maximum) also_max_subset++;

        for (int j = 1; j < nums.size(); ++j) {
            int ors_size = ors.size();

            for (int i = 0; i < ors_size; ++i) {
                int value = ors[i] | nums[j];
                if (value == maximum) 
                    also_max_subset++;
                ors.push_back(value);
            }
        }

        return also_max_subset;
    }
};