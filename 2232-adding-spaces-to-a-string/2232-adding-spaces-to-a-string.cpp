class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        // Final length of the result
        int totalLength = s.size() + spaces.size(); 
        // Pre-allocated buffer
        char result[totalLength]; 
        int sIndex = 0, spacesIndex = 0, resultIndex = 0;

        while (sIndex < s.size()) {
            if (spacesIndex < spaces.size() && sIndex == spaces[spacesIndex]) {
                // Insert space at the correct position
                result[resultIndex++] = ' '; 
                spacesIndex++;
            }
            // Copy the current character
            result[resultIndex++] = s[sIndex++]; 
        }

        // Convert the buffer to a string
        return string(result, totalLength); 
    }
};