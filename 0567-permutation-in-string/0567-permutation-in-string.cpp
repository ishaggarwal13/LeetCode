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

        int n1 = s1.size(), n2 = s2.size();
        if(n1 > n2) return false;

        unordered_map<char, int> mp1, mp2;

        for(int i=0; i<n1; i++){
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }

        for(int i=n1; i<n2; i++){
            if(mp1 == mp2) return true;
            mp2[s2[i-n1]]--;
            if(mp2[s2[i-n1]] == 0) mp2.erase(s2[i-n1]);
            mp2[s2[i]]++;
        }
        return mp1 == mp2;
    }
};