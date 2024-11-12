class Solution {
public:
    unordered_map<string, int> memo;

// Function to get the value with memoization
int getValue(int row, int col) {
    string key = to_string(row) + "," + to_string(col);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }
    
    // Base cases
    if (col == 0 || col == row) {
        return 1;
    }
    // Store the computed value
    memo[key] = getValue(row - 1, col - 1) + getValue(row - 1, col);
    return memo[key];
}
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1);
        for(int col=0; col<=rowIndex; col++){
            row[col] = getValue(rowIndex, col);
        }
        return row;
    }
};