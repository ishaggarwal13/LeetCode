class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), write = 0;
        for(int i = 0, j; i < n; ) {
            j = i;
            while(j < n && chars[j] == chars[i]) j++;

            if(j == i + 1) {
                chars[write++] = chars[i];
            }else {
                chars[write++] = chars[i];
                string count = std::to_string(j - i);
                for(char ch : count) chars[write++] = ch;
            }

            i = j;
        }
        return write;
    }
};