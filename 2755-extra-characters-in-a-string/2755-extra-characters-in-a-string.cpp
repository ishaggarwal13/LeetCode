class Solution {
bool startWith(string& s, int index, string& comp) {
        if (index + comp.size() > s.size()) {
            return false;
        }
        for (int i = 0; i < comp.size(); i++) {
            if (s[index + i] != comp[i]) {
                return false;
            }
        }
        return true;

    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<unsigned long> minDp(s.size()+1, s.size());
        unsigned long minChar = s.size();
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < dictionary.size(); j++) {
                if (startWith(s, i, dictionary[j])) {
                    for (int k = i+dictionary[j].size(); k <= s.size(); k++) {
                        minDp[k] = min(minDp[k], minDp[i] - dictionary[j].size());
                        // printf("k %d min %d i %d j %s\n", k, minDp[k], i, dictionary[j].c_str());
                        minChar = min(minChar, minDp[k]);
                    }
                }
            }
        }
        return minChar;
    }
};