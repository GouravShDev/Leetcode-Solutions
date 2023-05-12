class Solution {
public:
    long long solve(vector<vector<int>> &ques, int index, vector<int> &dp){
        if(index >= ques.size()) return 0;
        if(dp[index] != -1) return dp[index];
        long long ans = 0;
        for(int i = index; i < ques.size(); i++){
            ans = max(ans, ques[i][0] + solve(ques, i + ques[i][1] + 1, dp));
        }
        return dp[index] = ans;
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        vector<long long> prefMx(questions.size());
        prefMx[questions.size()-1] = questions[questions.size()-1][0];
        for(int i = questions.size()-2; i >= 0 ;i--){
            long long points = questions[i][0];
            long long brainpower = questions[i][1];
            
            int nextIndex = i + brainpower  + 1;
            if(nextIndex >= questions.size()){
                prefMx[i] = max(prefMx[i+1],points);
            }else{
                prefMx[i] = max(prefMx[i+1], points + prefMx[nextIndex]);
            }
        }
        // for(auto &it : prefMx) cout<<it<<" ";
        // return solve(questions, 0,dp);
        return *max_element(prefMx.begin(), prefMx.end());
    }
};