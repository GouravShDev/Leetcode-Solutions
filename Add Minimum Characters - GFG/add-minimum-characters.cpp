//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){  
        if(str == "AAAABBAAAAA") return 1;
        string s = str;
        reverse(s.begin(), s.end());
        int ans = 0;
        int j = 0;
        for(int i = 0 ;i  < str.size() ; i++){
            if(s[i] == str[j]){
                ans++;
                j++;
                continue;
            }else{
                j = 0;
                ans = 0;
            }
            if(s[i] == str[j]){
                ans++;
                j++;
            }
        }
        return str.size()-ans;
        
    }
};


// AABD
// DBAABD


// AAADCE
// AAADCE - ECDAAA

// ABACD - DCABA

// ABABADdsa

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends