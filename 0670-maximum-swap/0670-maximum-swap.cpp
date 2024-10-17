class Solution {
public:
    int maximumSwap(int num) {
        // convert into string and then declare array for storing last index of digit
        // stored the last index of digit into array
        // now perform for loop from 0 to n and another loop
        // from d=9 to d>str[i]-'0' at that index 
        // checks index at d at last index array is greater than index i
        // if yes then swap and return stoi(str)
        // after loop ends return original num

        string str = to_string(num);
        int n = str.size();

        int last[10] = {-1};

        for(int i=0; i<n; i++){
            last[str[i] - '0'] = i; // for eg 234 so at last[2] = 0
        }

        for(int i=0; i<n; i++){
            for(int d=9; d>str[i] - '0'; d--){
                if(last[d] > i){
                    swap(str[i], str[last[d]]);
                    return stoi(str);
                }
            }
        }
        return num;
    }
};