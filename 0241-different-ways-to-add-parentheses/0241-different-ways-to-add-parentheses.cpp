class Solution {
public:
    int help(int x, int y, char op){
        if(op == '+') return x+y;
        if(op == '-') return x-y;
        if(op == '*') return x*y;
        return 0;
        
    }
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
                        int val = help(x, y, exp[i]);
                        res.push_back(val);
                    }
                }
            }
        }

        if(isnum == true) res.push_back(stoi(exp));
        return res;
    }
};