//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    vector<string> perms;
	    set<string> st;
	    void solve(string s, int index){
	        if(index == s.size()){
	            if(st.count(s)) return;
	            perms.push_back(s);
	            st.insert(s);
	            return;
	        }
	        char lastPicked = '#';
	        for(int i = index ;i < s.size();i++){
	            if(s[i] != lastPicked){
	                swap(s[i], s[index]);
	                solve(s, index+1);
	                swap(s[i], s[index]);
	                lastPicked = s[i];
	            }
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    sort(S.begin() , S.end());
		    solve(S, 0);
		    sort(perms.begin(), perms.end());
		    return perms;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends