class Solution {
public:
    int getLucky(string s, int k) {
        string t="";
        for(char c:s){
            t+=to_string(c-'a'+1);
        }
        for(int i=0;i<k;i++){
        //     cout<<t<<' ';
            int num=0;
            for(auto i:t)num+=i-'0';
            t=to_string(num);
        }
        return stoi(t);
    }
};