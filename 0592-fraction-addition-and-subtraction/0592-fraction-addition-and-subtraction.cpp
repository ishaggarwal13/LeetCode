class Solution {
public:
    //O(n) and O(1)
    string fractionAddition(string expression) {
        istringstream in(expression); //Create an input string stream
        int A=0, B=1, a, b;
        char _; //Temporary variable to store the '/' character in the string
        while(in >> a >> _ >> b){ //extract numerator, / & denominator from the stream
            A = A * b + B * a;
            B = B * b;
            int g = abs(__gcd(A, B));
            A /= g;
            B /= g;
        } 

        return to_string(A) + "/" + to_string(B);
    }
};