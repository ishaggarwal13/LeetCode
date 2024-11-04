class Solution {
public:
    string compressedString(string word) {
        if (word.empty()) return "";

        std::vector<char> comp;
        int count = 1;
        int n = word.size();
        char ch = word[0];
        
        for(int i = 1; i < n; i++) {
            if(word[i] == ch && count < 9) { // Count up to 9
                count++;
            } else {
                comp.push_back(count + '0'); // Convert count to char and append
                comp.push_back(ch); 
                ch = word[i];
                count = 1; // Reset count
            }
        }
        comp.push_back(count + '0'); // Add the final count
        comp.push_back(ch); // Add the last character

        return std::string(comp.begin(), comp.end()); // Construct final string from vector
    }
};