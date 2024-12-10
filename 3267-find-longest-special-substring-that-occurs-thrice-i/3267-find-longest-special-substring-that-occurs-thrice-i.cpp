class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int>um;

        for (int i{(int)s.size()-2}, ss{(int)s.size()}; i > 0; --i){
            for (int j{}; j+(i-1) < ss; ++j){
                bool same{true};

                for (int k{1}; k < i; ++k){
                    if (s[j+k] != s[(j+k)-1]){
                        same = false; break;
                    }
                }

                if (same && ++um[s.substr(j, i)] == 3){
                    return i;
                }
            }
        }

        return -1;
    }
};