class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // first will check is s1 size is larger than s2 size return false
        // decalre unordered map for both string storing s1 and s2 window till s1 size
        // now iterate from s1 size to s2 size 
        // check if map are equal return true
        // reducing the size first element in map by 1 
        // now remove/earse the elemnt if it is 0
        // now adding next element 
        // which means moving the window by one and by removing previosu one
        // return if map are equal

        if (s1.length() > s2.length()) return false;

        vector<int> s1Count(26, 0), s2Count(26, 0);
        
        // Count frequencies of s1 and the first window in s2
        for (int i = 0; i < s1.length(); ++i) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        // Slide the window over s2
        for (int i = 0; i < s2.length() - s1.length(); ++i) {
            if (s1Count == s2Count) return true;
            // Update the window
            s2Count[s2[i] - 'a']--;
            s2Count[s2[i + s1.length()] - 'a']++;
        }

        // Check the last window
        return s1Count == s2Count;
    }
};