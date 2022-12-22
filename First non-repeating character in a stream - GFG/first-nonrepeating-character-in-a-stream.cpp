//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    int lastCharInd = 0;
		    vector<int> freq(26);
		    string ans = "";
		    for(int i =0 ;i  <  A.size(); i++){
		        freq[A[i]-'a']++;
		        while(lastCharInd <= i && freq[A[lastCharInd]-'a'] > 1){
		            lastCharInd++;
		        }
		        if(lastCharInd >i){
		            ans +='#';
		        }else{
		            ans += A[lastCharInd];
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends