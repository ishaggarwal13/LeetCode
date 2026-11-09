class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n=arr.size();
        int i=0, j=1;
        vector<int>ans(n);
        for(int k=0; k<n; k++){
            if(arr[k]>0){
                ans[i]=arr[k];
                i=i+2;
            }
            else{
                ans[j]=arr[k];
                j=j+2;
            }
        }
        return ans;
    }
};