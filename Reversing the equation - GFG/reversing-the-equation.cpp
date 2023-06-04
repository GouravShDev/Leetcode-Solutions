//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    bool isOperator(char c){
        return c == '+' || c == '-' || c == '*' || c == '/';
    }
    string reverseEqn (string s)
        {
            string ans = "";
            string cur = "";
            for(int i = s.size()-1 ;i >= -1; i--){
                if(i == -1 || isOperator(s[i]) ){
                    for(int j = cur.size()-1; j >= 0; j--){
                        ans += cur[j];
                    }
                   cur = "";
                   if(i >= 0) ans += s[i];
                }else{
                    cur += s[i];
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends