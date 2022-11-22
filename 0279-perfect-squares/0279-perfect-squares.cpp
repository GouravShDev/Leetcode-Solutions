class Solution {
public:
    vector<int> sqrs;
    int numSquares(int n) {
        int mxSq = 1001;
        sqrs.resize(mxSq);
        for(int i = 0;  i < mxSq; i++){
            sqrs[i] = i * i;
        }
        queue<int> q;
        vector<int> dp(mxSq * 10, INT_MAX);
        q.push(n);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i =0 ;i  < size; i++){
                int cur = q.front();
                q.pop();
                if(cur == 0) return level;
                for(int j = 0;j  < 1001 && cur >= sqrs[j]; j++){
                    if(dp[cur- sqrs[j]] > level){
                        q.push(cur - sqrs[j]);
                        dp[cur-sqrs[j]] = level;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};