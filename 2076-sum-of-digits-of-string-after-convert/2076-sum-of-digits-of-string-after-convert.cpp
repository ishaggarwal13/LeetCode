class Solution {
public:
    int getLucky(string s, int k) {
        string str="";
        for(int i=0;i<s.length();i++)
            str=str+ to_string(s[i]-'a'+1);
        while(k!=0)
        {
            int ans=0;
            for(int i=0;i<str.length();i++)
                ans=ans+str[i]-'0';
            str=to_string(ans);
            k--;
        }
        return stoi(str);
    }
};