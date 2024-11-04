class Solution {
public:
    string compressedString(string word) {
        std::ostringstream comp; // Ostringstream for efficient string building
        int count = 1;
        int n = word.size();
        
        if (n == 0) return comp.str(); // Handle empty input case early
        
        char ch = word[0];
        for(int i = 1; i < n; i++) {
            if(word[i] == ch && count < 9) { // Assuming you want a count up to 9
                count++;
            } else {
                comp << count << ch; // Directly append count and character
                ch = word[i]; // Update ch to the new character
                count = 1; // Reset count
            }
        }
        comp << count << ch; // Add the count and last character

        return comp.str();
    }
};