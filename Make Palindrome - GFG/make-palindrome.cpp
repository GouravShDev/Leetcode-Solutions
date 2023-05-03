//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
bool isPalindrome(string str){
    int i =0 ;
    int j = str.size()-1;
    while(i < j){
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}
    bool makePalindrome(int n,vector<string> &arr){
        map<string, int> st;
        for(auto it : arr){
            if(st.find(it) != st.end()){
                st[it]--;
                if(st[it] == 0 ) st.erase(it);
            }else{
                reverse(it.begin(), it.end());
                st[it]++;
            }
        }
        if(st.size() > 1) return false;
        if(st.size() == 1)return isPalindrome(st.begin()->first);
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends