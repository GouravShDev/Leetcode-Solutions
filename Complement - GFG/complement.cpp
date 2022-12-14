//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {
        int left = 0;
        int sum = 0;
        int mxSum = 0;
        vector<int> ans({-1});
        for(int i =0 ;i  < str.size(); i++){
            if(str[i] == '0'){
                sum++;
            }else{
                sum--;
            }
            if(sum < 0){
                sum = 0;
                left  = i+1;
            }
            if(sum > mxSum){
                ans = {left+1 , i+1};
                mxSum = sum;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends