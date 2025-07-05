class Solution {
public:
    int findLucky(vector<int>& arr) {
       unordered_map<int, int> freq;
        for(int x: arr) freq[x]++;
        int max_lucky_no=-1;
        for(auto f: freq){
            if(f.first==f.second)
                max_lucky_no=max(max_lucky_no, f.first);
        }
        return max_lucky_no;
    }
};