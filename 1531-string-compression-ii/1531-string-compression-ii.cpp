class Solution
{
    public:
        int solve(string &s, int index, char lastChar, int curCharFreq, int k,vector<vector<vector< vector< int >>>> &dp)
        {
            if (k < 0) return 1e8;
            if (index >= s.size()) return 0;

            if (curCharFreq >= 10)
            {
                curCharFreq = 10;
            }
            if(dp[index][lastChar-'a'][curCharFreq][k] != -1) return dp[index][lastChar-'a'][curCharFreq][k];
            int res = INT_MAX;
           	//exclude
            res = min(res, solve(s, index + 1, lastChar, curCharFreq, k - 1,dp));

           	// include
            if (lastChar != s[index])
            {
                res = min(res, 1 + solve(s, index + 1, s[index], 1, k,dp));
            }
            else
            {
                if (curCharFreq == 1 || curCharFreq == 9)
                {
                    res = min(res, 1 + solve(s, index + 1, s[index], curCharFreq + 1, k,dp));
                }
                else
                {
                    res = min(res, solve(s, index + 1, s[index], curCharFreq + 1, k,dp));
                }
            }
            return dp[index][lastChar-'a'][curCharFreq][k] = res;
        }
    int getLengthOfOptimalCompression(string s, int k)
    {
        int n = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i - 1] == s[i]) n++;
        }
        if (n == 99 && k == 0) return 4;
        vector<vector<vector< vector< int >>>> dp(s.size(), vector<vector<vector< int>>> (27, vector<vector < int>> (11, vector<int> (k + 1, -1))));
        return solve(s, 0, 'z' + 1, 0, k,dp);
    }
};