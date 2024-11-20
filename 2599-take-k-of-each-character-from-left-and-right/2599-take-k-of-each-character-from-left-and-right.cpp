class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int>v(3,0);
        int n=s.length();
        int a=0,b=0,c=0;
        if(k==0)return 0;
        for(int i=0;i<n;i++){
           v[s[i]-'a']++;
        }
        for(int i=0;i<3;i++){
            if(v[i]<k)return -1;
        }
         
         int ans=0;
         int i=0,j=0;
        vector<int>res(3,0);

        for(i=0;i<n;i++){
            res[s[i]-'a']++;

            while(j<=i && (v[0]-res[0]<k || v[1]-res[1]<k || v[2]-res[2]<k)){
                res[s[j]-'a']--;
                j++;
                  
            }
          ans=max(ans,i-j+1);
             

        }
       
        return n-ans;
    }
};