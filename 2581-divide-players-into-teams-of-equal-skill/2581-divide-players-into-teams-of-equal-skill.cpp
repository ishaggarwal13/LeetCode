class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        vector<pair<int,int>> ans;
        sort(skill.begin(),skill.end());
        if(skill.size()==2){
          return skill[0]*skill[1];
        }
        int val = skill[0]+skill[skill.size()-1];
        long long prod=0;
        for(int i=0;i<skill.size()/2;i++){
          if(val != (skill[i]+skill[skill.size()-i-1])){
            return -1;
          }
          prod += (long long)skill[i]*(long long)skill[skill.size()-i-1];
        }
        
        return prod;
    }
};