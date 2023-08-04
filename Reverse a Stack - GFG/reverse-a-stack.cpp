//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void insertAtBottom(stack<int> &stk , int ele){
        // {3} 4
        // {3, 4} 
        if(stk.empty()){
            stk.push(ele);
            return;
        }
        int topEle = stk.top();
        stk.pop();
        insertAtBottom(stk, ele);
        stk.push(topEle);
    }
    void solve(stack<int> &stk){
        if(stk.empty()) {
            return;
        }
        int element = stk.top();
        stk.pop();
        solve(stk);
        insertAtBottom(stk, element);
    }
    void Reverse(stack<int> &St){
        solve(St);
        return ;
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends