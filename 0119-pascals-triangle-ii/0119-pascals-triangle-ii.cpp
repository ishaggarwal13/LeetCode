class Solution {
public:
    vector<int> getRow(int rowIndex) {
       vector<int> row(rowIndex + 1, 1); // Initialize row with all elements as 1

    // Iteratively update the row from the end to the start for each row level
    for (int i = 1; i < rowIndex; i++) {  
        for (int j = i; j > 0; j--) {  
            row[j] = row[j] + row[j - 1]; // Update each element by summing up the two elements above it
        }
    }

    return row;
    }
};