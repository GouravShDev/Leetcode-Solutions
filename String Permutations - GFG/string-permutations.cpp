//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void solve(string &s, int index, vector<string> &ans){
        if(index == s.size()){
            ans.push_back(s);
            return;
        }
        for(int i = index; i < s.size(); i++){
            swap(s[i], s[index]);
            solve(s, index+1, ans);
            swap(s[i], s[index]);
        }
    }
    vector<string> permutation(string S)
    {
        vector<string> ans;
        solve(S, 0, ans);
        sort(ans.begin() ,ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends