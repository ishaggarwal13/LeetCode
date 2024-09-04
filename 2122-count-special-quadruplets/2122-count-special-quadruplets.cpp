class Solution {
public:
    int countQuadruplets(vector<int>& arr) {
        //O(n^2) and O(n)
        int c=0,n=arr.size();
        map<int,int>mp;
       
         for(int i=n-1;i>=2;i--){
             for(int j=i-1;j>=1;j--){
                 for(int k=j-1;k>=0;k--){  
                     if(mp[arr[i]+arr[j]+arr[k]])
                         c+=mp[arr[i]+arr[j]+arr[k]];
                    
                 }
             }
             mp[arr[i]]++;
             
         }
         return c;
    }
};