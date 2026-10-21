class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        //if string is already sorted
        if(is_sorted(s.begin(), s.end()))
            return 0;

        //length is 2 can't be sorted
        if(n == 2) return -1;

        //find chracter mini and maxi
        char mini = *min_element(s.begin(), s.end());
        char maxi = *max_element(s.begin(), s.end());

        //if max or min char at its correct position
        if(s[0] == mini || s[n-1] == maxi)
            return 1;
        
        //if min or max is not at end and start
        if(s.find(mini) < n-1 || s.rfind(maxi) > 0)
            return 2;

        return 3;
    }
};