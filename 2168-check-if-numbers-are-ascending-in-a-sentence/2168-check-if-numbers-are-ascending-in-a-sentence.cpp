class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> numbers;
        int num=0;
        bool isnum = false;
        for(auto c : s){
            if(isdigit(c)){
                num = num*10 + (c - '0');
                isnum = true;
            } else{
                if(isnum){
                    numbers.push_back(num);
                    num=0; //set back to 0
                    isnum = false;
                }
            }
        }
        //add last number to numbers vector
        if(isnum){
           numbers.push_back(num); 
        }

        for(int i=1; i<numbers.size(); i++){
            if(numbers[i-1] >= numbers[i]){
                return false;
            }
        }
        return true;
    }
};