class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > grid(m, vector<int>(n));
        // cout << m << " " << n << endl;
        //range of the length of diagonal: 0 ~ (max possible i) + (max possible j)
        for(int diag = 0; diag <= (n-1) + (m-1); diag++){
            //i starts from the first position that j >= 0
            //i is increased in the loop and its upper bound is m-1
            //j + i must = diag
            //j is decreased in the loop and its lower bound is 0
            //dynamic programming
            for(int i = max(0, diag-(n-1)), j = diag - i; i <= m-1 && j >= 0; i++, j--){
                // cout << i << " " << j << endl;
                if(i == 0 || j == 0){
                    grid[i][j] = 1;
                }else{
                    grid[i][j] = grid[i-1][j] + grid[i][j-1];
                }
            }
        }

        return grid[m-1][n-1];
    }
};
