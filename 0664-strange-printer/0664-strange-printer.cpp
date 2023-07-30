class Solution {
public:
    int solve(string &s, int i, int j, int pickedIndex, vector<vector<vector<int>>> &dp){
      //  if(i > j) return 0;
        if(dp[i][j][pickedIndex] != -1) return dp[i][j][pickedIndex];
        dp[i][j][pickedIndex] = s.size();
        int k = -1;
        for(int index = i; index < j ; index++){
            if(s[index] != s[j] && k == -1){
                k = index;
            }
            if(k != -1) 
            dp[i][j][pickedIndex] = min(dp[i][j][pickedIndex], 1 + solve(s, k , index, pickedIndex, dp) + solve(s, index+1 , j, pickedIndex,dp));
        }
        if(k == -1) dp[i][j][pickedIndex] = 0;
        return dp[i][j][pickedIndex];
    }
    int strangePrinter(string s) {
        string newStr = s;
        // char lastCh = '#';
        // for(auto &i : s){
        //     if(i != lastCh){
        //         newStr+= i;
        //     }
        //     lastCh = i;
        // }
        vector<vector<vector<int>>> dp(newStr.size(), vector<vector<int>>(newStr.size(),vector<int>(newStr.size()+1, -1)));
        return solve(newStr, 0, newStr.size()-1, 0, dp)+1;
    }
};

// abcd = 4

// abcdab

// abcddab = 4

// abcabc = abcabc

// aaabba ==> aba
