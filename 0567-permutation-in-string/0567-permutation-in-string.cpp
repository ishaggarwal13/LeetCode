class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        
        if (n1 > n2) return false;

        unordered_map<char, int> ctr1, ctr2;

        for (int i = 0; i < n1; ++i) {
            ctr1[s1[i]]++;
            ctr2[s2[i]]++;
        }

        for (int i = n1; i < n2; ++i) {
            if (ctr1 == ctr2) return true;
            ctr2[s2[i - n1]]--;  
            if (ctr2[s2[i - n1]] == 0) ctr2.erase(s2[i - n1]); 
            ctr2[s2[i]]++;
        }
        return ctr1 == ctr2;
    }
};