class Solution {
public:
    int findTheLongestSubstring(string s) {
        //O(n) & O(1) using bitmask and leftshift
        int n = s.size();
        int mask = 0, maxi = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;

        for(int i=0; i<n; i++){
            if(s[i] == 'a') mask ^= (1 << 0); //shifting the bit to left by 1 to 0 position
            else if(s[i] == 'e') mask ^= (1 << 1);
            else if(s[i] == 'i') mask ^= (1 << 2);
            else if(s[i] == 'o') mask ^= (1 << 3);
            else if(s[i] == 'u') mask ^= (1 << 4);

            if(mp.find(mask) != mp.end()){
                maxi = max(maxi, i - mp[mask]);
            } else {
                mp[mask] = i;
            }
        }
        return maxi;
    }
};