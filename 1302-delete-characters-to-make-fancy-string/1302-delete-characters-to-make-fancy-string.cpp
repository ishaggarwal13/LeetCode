class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int streak = 1;
        char last = '9';


        for(int i = 0; i<s.size(); i++){
            //cout << last << " " << s[i] << " " << streak << endl;
            if(last == s[i]){
                streak++;
            } else {
                last = s[i];
                streak = 1;
            }
            

            if(streak >= 3) continue;

            ans.push_back(s[i]);
            
        }

        return ans;
    }
};