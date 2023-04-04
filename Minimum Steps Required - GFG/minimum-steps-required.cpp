//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    int a= 0;
    int b= 0;
    char lastCh = '#';
    for(int i =0 ; i < str.size();i++){
        if(str[i] != lastCh){
            if(str[i] == 'a'){
                b++;
            }else{
                a++;
            }
        }
        lastCh = str[i];
    }
    return min(a,b) + 1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends