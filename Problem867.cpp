class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        // Get the number of rows (n) and columns (m) in the matrix
        int n = matrix.size();
        int m = matrix[0].size();

        // Create a 2D vector to store the transposed matrix
        vector<vector<int>> ans;

        // Iterate over each column of the original matrix
        for (int j = 0; j < m; j++) {
            // Create a temporary vector to store the values of the current transposed row
            vector<int> temp;

            // Iterate over each row of the original matrix
            for (int i = 0; i < n; i++) {
                // Add the value at matrix[i][j] to the temporary vector
                temp.push_back(matrix[i][j]);
            }

            // Add the temporary vector to the transposed matrix
            ans.push_back(temp);
        }

        // Return the transposed matrix
        return ans;
    }
};
