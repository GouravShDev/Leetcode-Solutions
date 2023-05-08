class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int i1 = 0;
        int j1 = 0;
        int i2 = 0;
        int j2 = n-1;
        int sum = 0;
        for(int i = 0;  i < n; i++ ){
            sum += mat[i1][j1];
            i1++;
            j1++;
            if(i2 != j2) sum += mat[i2][j2];
            
            i2++;
            j2--;
        }
        return sum;
    }
    
};