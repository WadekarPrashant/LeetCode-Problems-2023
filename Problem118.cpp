class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a(numRows);
        for(int&& i=0; i<numRows; i++){
            a[i].assign(i+1, 1);// exact allocation once
            for(int&& j=1; j<=i/2; j++){
                  a[i][i-j]=a[i][j]=a[i-1][j-1]+a[i-1][j];

            }
        }
        return a;
    }
};
