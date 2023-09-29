//Given an integer numRows, return the first numRows of Pascal's triangle.

//In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// Example 2:


// Using formala  
class Solution {
public:
    
    vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
        
    vector<vector<int>> generate(int numRows) {

            vector<vector<int>> ans;

    //store the entire pascal's triangle:
        for (int row = 1; row <= numRows; row++) {
        ans.push_back(generateRow(row));
    }
           return ans;
} 
  
};

// using single loop -> faster but takes more Space
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;
        // Base cases...
        if(numRows == 0)  return output;
        // Traverse all the elements through a loop
        for(int i=0; i<numRows; i++)
            output.push_back(vector<int>(i + 1, 1));    // Initialize the first row of the pascal triangle as {1}.
        // For generating each row of the triangle...
        for (int i = 2; i < numRows; ++i)
            // Run an inner loop from j = 1 to j = {previous row size} for calculating element of each row of the triangle.
            for (int j = 1; j < output[i].size() - 1; ++j)
                // Calculate the elements of a row, add each pair of adjacent elements of the previous row in each step of the inner loop.
                output[i][j] = output[i - 1][j - 1] + output[i - 1][j];
        return output;      // After the inner loop gets over, simply output the row generated.
    }
};
