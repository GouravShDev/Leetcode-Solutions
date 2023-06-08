//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    void nextPermuation(vector<int> &perm){
        int index = -1;
        for(int i = perm.size()-2;  i >= 0; i--){
            if(perm[i] < perm[i+1]){
                index = i;
                break;
            }
        }
        int smallValIndex = index;
        for(int i = perm.size()-1; index != -1 && i > index;i--){
            if(perm[index] < perm[i]){
                smallValIndex= i;
                break;
            }
        }
        if(index == -1){
            reverse(perm.begin(), perm.end());
            return;
        }
        swap(perm[index], perm[smallValIndex]);
        reverse(perm.begin() + index +1, perm.end());
    }
    string kthPermutation(int n, int k)
    {
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 1);
        while(--k){
            nextPermuation(perm);
        }
        string ans;
        for(auto &it: perm){
            ans += to_string(it);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends