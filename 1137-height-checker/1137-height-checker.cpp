class Solution {
public:
    int heightChecker(vector<int>& heights) {
       vector<char> sorted(heights.begin(), heights.end());
        // counting sort
        char freq[101]={0};
        for(char x: sorted) freq[x]++;
        int cnt=0;
        for (int x=1; x<=100; x++){
            int f=freq[x];
            fill(sorted.begin()+cnt, sorted.begin()+cnt+f, x);
            cnt+=f;
        }
        //end of count sort

        int n=heights.size(), ans=0;
        for(int i=0; i<n; i++)
            ans+=(heights[i]!=sorted[i]);
        return ans;
    }
};