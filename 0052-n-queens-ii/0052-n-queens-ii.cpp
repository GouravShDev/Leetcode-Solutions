class Solution {
public:
    bool isSafe(int n,int row, int col, vector<int> &colFlag , vector<int> &leftDiagonal, vector<int> &rightDiagonal){
        return colFlag[col] || leftDiagonal[row+col] || rightDiagonal[n-1 - (col-row )];
    }
    int solve(int n ,int index, vector<int> &colFlag, vector<int> &leftDiagonal, vector<int> &rightDiagonal){
        if(index == n){
            return 1;
        }
        int ans = 0;
        for(int i = 0; i < n ; i++){
            if(!isSafe(n, index, i , colFlag, leftDiagonal, rightDiagonal)){
                colFlag[i] = 1;
                leftDiagonal[index + i] = 1;
                rightDiagonal[n-1 - (i- index)] = 1;
                
                ans += solve(n , index+1, colFlag, leftDiagonal, rightDiagonal);
                
                colFlag[i] = 0;
                leftDiagonal[index + i] = 0;
                rightDiagonal[n-1 - (i- index)] = 0;
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
        vector<int> colFlag(n);
        vector<int> leftDiagonal(2 * n);
        vector<int> rightDiagonal(2 * n );
        return solve(n , 0, colFlag, leftDiagonal, rightDiagonal);
    }
};