class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        int sRowIndex = 0;
        int sColIndex = 0;
        int eRowIndex = n-1;
        int eColIndex = m-1;
        while(sRowIndex <= eRowIndex || sColIndex <= eColIndex){
            for(int j = sColIndex; j <= eColIndex; j++){
                ans.push_back(matrix[sRowIndex][j]);
            }
            sRowIndex++;
            if(sRowIndex > eRowIndex) break;
            for(int i = sRowIndex; i <= eRowIndex; i++){
                ans.push_back(matrix[i][eColIndex]);
            }
            eColIndex--;
            if(eColIndex < sColIndex) break;
            for(int j = eColIndex; j >= sColIndex; j--){
                ans.push_back(matrix[eRowIndex][j]);
            }
            eRowIndex--;
            if(eRowIndex < sRowIndex) break;
            for(int i = eRowIndex; i >= sRowIndex; i--){
                ans.push_back(matrix[i][sColIndex]);
            }
            sColIndex++;
            if(sColIndex > eColIndex) break;
                
        }
        return ans;
    }
};