class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        constexpr int N{100'000};
        std::array<bool, N+1> ns{};

        for(const int i : nums) { ns[i] = true; }

        int ans{-1};

        for(size_t i{0}; i<N; ++i) {
            if (ns[i] == false) { continue; }

            int len{0};
            size_t index{i};
            while(index < N && ns[index]) {
                ++len;
                index = index * index;
            }

            if (len > 1) { ans = std::max(ans, len); }
        }

        return ans;
    }
};