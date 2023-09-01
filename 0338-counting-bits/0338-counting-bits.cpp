class Solution {
public:
    int solve(int x ){
        int count = 0;
        while(x){
            x &= (x-1);
            count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0 ; i <= n ; i++){
            ans.push_back(solve(i));
        }
        return ans;
    }
};