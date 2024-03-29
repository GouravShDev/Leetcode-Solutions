//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
       vector<int> sufMx(a, a+n);
       vector<int> ans;
       for(int i = n-2; i >= 0; i--){
           sufMx[i] = max(sufMx[i], sufMx[i+1]);
       }
      int curMx = INT_MIN;
       for(int i = 0 ;i < n ; i++){
            if(curMx <= a[i] && (i == n-1 || a[i] >= sufMx[i+1])){
                ans.push_back(a[i]);
            }
            // curMx = max(a[i], curMx);
       }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends