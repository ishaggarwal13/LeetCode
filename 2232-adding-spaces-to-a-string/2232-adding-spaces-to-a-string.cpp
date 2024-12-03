class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        std::string result(s.size() + spaces.size(), ' ');
        size_t tracker = 0, k = 0;
        for (size_t i = 0; i < s.size(); ++i, ++k) {
            if (tracker < spaces.size() and i == spaces[tracker]) {
                ++tracker;
                ++k;
            }
            result[k] = s[i];
        }
        return result;
    }
};