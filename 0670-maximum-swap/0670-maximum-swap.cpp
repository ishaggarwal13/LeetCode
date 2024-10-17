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
        string s1 = str;
        int n = s1.size();

        for(int i=0; i<n; i++){
            int index = getmax(str, i);
            swap(str[i], str[index]);
            if(s1 != str){
                break;
            }
        }
        int number = stoi(str);
        return number;
    }
    static int getmax(string str, int i){
        int max = i;
        for(int j=i; j<str.length(); j++){
            if(str[max] <= str[j]){
                max = j;
            }
        }
        return max;
    }
};