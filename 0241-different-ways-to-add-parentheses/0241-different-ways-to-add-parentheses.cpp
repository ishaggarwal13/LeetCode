class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> res;
        bool isnum = true;
        for(int i=0; i<exp.size(); i++){
            if(!isdigit(exp[i])){
                //it is not a number
                isnum = false;

                vector<int> left = diffWaysToCompute(exp.substr(0, i));

                vector<int> right = diffWaysToCompute(exp.substr(i+1));

                for(int x : left){
                    for(int y : right){
                        if(exp[i] == '+') 
                            res.push_back(x+y);
                        else if(exp[i] == '-') 
                            res.push_back(x-y);
                        else
                            res.push_back(x*y);
                    }
                }
            }
        }

        if(isnum == true) res.push_back(stoi(exp));
        return res;
    }
};