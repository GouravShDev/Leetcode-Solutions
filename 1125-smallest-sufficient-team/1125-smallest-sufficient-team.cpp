class Solution {
public:
    vector<int> ans;
    unordered_map<string, int> skillMp;
    void solve(vector<int> &people, int index, int req, vector<int>& curTeam,vector<map<int,int>> &dp){
        if(req == 0){
            if(ans.empty() || ans.size() > curTeam.size()){
             ans = curTeam;   
            }
            return;
        }
        if(index == people.size() ||(!ans.empty() && curTeam.size() >= ans.size())){
            return;
        }
        if(dp[index].count(req)) return;
        solve(people, index+1, req, curTeam,dp);
        bool containsReq = (req & people[index]) > 0;
       
        if(containsReq){
        // for(int i = 0;i < 32 ;i ++){
        //     int mask = 1 << i;
        //     if((req & mask ) > 0 && (people[index] & mask) > 0){
        //         req ^= mask;
        //     }
        // }
            req = req & (~people[index]);
            curTeam.push_back(index);
            solve(people, index + 1, req, curTeam,dp);
            curTeam.pop_back();
        }
        dp[index][req] = 1;
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        unordered_map<int, vector<int>> dp;
        dp.reserve(1 << n); // reserve space and avoid hash collisions
        dp[0] = {};
        unordered_map<string, int> skill_index;
        for (int i = 0; i < req_skills.size(); ++i)
            skill_index[req_skills[i]] = i;
        for (int i = 0; i < people.size(); ++i) {
            int cur_skill = 0;
            for (auto& skill: people[i])
                cur_skill |= 1 << skill_index[skill];
            for (auto it = dp.begin(); it != dp.end(); ++it) {
                int comb = it->first | cur_skill;
                if (dp.find(comb) == dp.end() || dp[comb].size() > 1 + dp[it->first].size()) {
                    dp[comb] = it->second;
                    dp[comb].push_back(i);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};