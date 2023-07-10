//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
        int startRow = 0;
        int startCol = 0;
        int endRow = n-1;
        int endCol = m-1;
        while(startRow <= endRow && startCol <= endCol){
            for(int j = startCol ;j <= endCol ; j++){
                k--;
                if(k == 0) return a[startRow][j];
            }
            startRow++;
            for(int i = startRow;i <= endRow; i++){
                k--;
                if(k == 0) return a[i][endCol];
            }
            endCol--;
            for(int j = endCol; j >= startCol; j--){
                k--;
                if(k == 0) return a[endRow][j];
            }
            endRow--;
            for(int i = endRow; i >= startRow; i--){
                k--;
                if(k == 0) return a[i][startCol];
            }
            startCol++;
        }
        return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends