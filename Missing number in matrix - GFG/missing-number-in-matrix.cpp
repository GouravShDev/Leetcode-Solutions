//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long int MissingNo(vector<vector<int> >& mat) {
        set<long long> st;
        vector<vector<long long>> matrix(mat.size() , vector<long long>(mat[0].size()));
        for(int i =0 ;i < mat.size(); i ++){
            for(int j = 0; j< mat.size(); j++){
                matrix[i][j] = mat[i][j];
            }
        }
            long long leftDiag = 0;
            long long rightDiag = 0;
            long long missingSum = 0;
        for(int i =0 ;i < matrix.size() ; i++){
            long long rowSum = 0;
            long long colSum = 0;
            int flag = 0;
            for(int j = 0 ;j < matrix.size() ; j++){
                rowSum += matrix[i][j];
                colSum += matrix[j][i];
                if(matrix[i][j] == 0){
                    flag = 1;
                }
                if(i == j) leftDiag += matrix[i][j];
                if(j== matrix.size()-i-1) rightDiag += matrix[i][j];
            }
            if(flag) missingSum = rowSum;
            st.insert(rowSum);
            st.insert(colSum);
        }
            st.insert(leftDiag);
            st.insert(rightDiag);
            // if(st.size() > 2) return -1;
        // for(auto &it : st){
        //     cout<<it<<" ";
        // 
        long long commonSum = *st.rbegin();
        long long missingNum =  *st.rbegin() - missingSum;
        // cout<<missingNum<<endl;
        leftDiag = 0;
        rightDiag = 0;
        for(int i = 0 ; i < matrix.size(); i++){
            long long rowSum = 0;
            long long colSum = 0;
            for(int j = 0;j  < matrix.size(); j++){
                // long long s = 0;
                if(matrix[i][j]== 0){
                    // if(missingNum == 0){
                        // missingNum = *st.begin() / matrix.size();
        // cout<<missingNum;
                    // }
                    matrix[i][j] = missingNum;
                    // s = missingNum;
                    // cout<<missingNum;
                }
                if(matrix[j][i] == 0){
                    matrix[j][i] = missingNum;
                }
                rowSum += matrix[i][j] ;
                colSum += matrix[j][i] ;
                if(i == j) leftDiag += matrix[i][j];
                if(j== matrix.size()-i-1) rightDiag += matrix[i][j];
            }
            // cout<<colSum <<" "<<commonSum<<endl;
            if(rowSum != commonSum) return -1;
            if(colSum != commonSum) return -1;
        }
        if(commonSum != leftDiag || rightDiag != commonSum) return -1;
        if(missingNum == 0 )return -1;
        return missingNum;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends