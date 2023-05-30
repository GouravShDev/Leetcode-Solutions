//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  string convert(string str){
      string ans = "";
      for(int i = 0;i < str.size() ; i++){
          if(isupper(str[i])) ans+= str[i];
      }
      return ans;
  }
  bool contains(string str, string pattern){
     if(pattern.size() < str.size()) return false;
      return pattern.substr(0, str.size()) == str;
  }
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        vector<string> ans;
        for(auto str : Dictionary){
            if(contains(Pattern, convert(str))) ans.push_back(str);
        }
      sort(ans.begin(), ans.end());
        if(ans.empty()) cout<<"-1";
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends