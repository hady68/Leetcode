// // Description
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.

// Example 1:
// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]

// Example 2:
// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 
// Constraints:
// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1
 
// Follow up:
// A straightforward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?


// Brute -> Solved using Matrix with Extra space. TC : O((NM)(N+M)), SC : O(N*M)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> visited = matrix;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    for(int k=0; k<m; k++){
                        visited[i][k] = 0;
                    }
                    for(int k=0; k<n; k++){
                        visited[k][j] = 0;
                    }
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                matrix[i][j] = visited[i][j];
            }
        }
    }
};



// withou extra space -> mark all non zero in relevant ror with a num and then replace those num with zero at the end
//Time Complexity: O((N*M)*(N + M)) + O(N*M)
// Space -> O(1)
class Solution {
public:
    void markrow(vector<vector<int>>& matrix, int i, int n) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -999;
            }
        }
    }

    void markcol(vector<vector<int>>& matrix, int j, int m) {
        for (int i = 0; i < m; i++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -999;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    markrow(matrix, i, n);
                    markcol(matrix, j, m);
                }
            }
        }

        // Mark all -1 as 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -999) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


// Solution 3 : Using 2 arrays and storing row, col index wwhere 0 is encountred then run another loop to mark them zero

// Tc -> Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
// Space Complexity: O(N) + O(M), where N = no. of rows in the matrix and M = no. of columns in the matrix.

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    int row[n] = {0}; // row array
    int col[m] = {0}; // col array

    // Traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark ith index of row wih 1:
                row[i] = 1;

                // mark jth index of col wih 1:
                col[j] = 1;
            }
        }
    }

    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }


// OPTIMAL 
