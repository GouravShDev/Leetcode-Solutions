class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n , vector<int> (n));
        // int n = matrix.size();
        // int m = matrix[0].size();
        // vector<int> ans;
        int sRowIndex = 0;
        int sColIndex = 0;
        int eRowIndex = n-1;
        int eColIndex = n-1;
        int count = 0;
        while(sRowIndex <= eRowIndex || sColIndex <= eColIndex){
            for(int j = sColIndex; j <= eColIndex; j++){
                ans[sRowIndex][j] = ++count;
            }
            sRowIndex++;
            if(sRowIndex > eRowIndex) break;
            for(int i = sRowIndex; i <= eRowIndex; i++){
                ans[i][eColIndex]  = ++count;
            }
            eColIndex--;
            if(eColIndex < sColIndex) break;
            for(int j = eColIndex; j >= sColIndex; j--){
                ans[eRowIndex][j]  = ++count;;
            }
            eRowIndex--;
            if(eRowIndex < sRowIndex) break;
            for(int i = eRowIndex; i >= sRowIndex; i--){
                ans[i][sColIndex]  = ++count;;
            }
            sColIndex++;
            if(sColIndex > eColIndex) break;
                
        }
        return ans;
    }
};