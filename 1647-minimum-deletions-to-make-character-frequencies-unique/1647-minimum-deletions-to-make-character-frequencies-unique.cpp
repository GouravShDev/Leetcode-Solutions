class Solution {
public:
    int minDeletions(string s) {
        map<char,int> mp;
        for(auto c : s){
            mp[c]++;
        }
        vector<int> vp;
        for(auto &it: mp){
            vp.push_back(it.second);
        }
        sort(vp.begin(), vp.end(), [](auto &a, auto &b){
            return a > b;
        });
        int ans = 0;
        int cur = 0;
        for(int i = 0 ;i < vp.size()-1; i++){
            
            while(vp[i] <= vp[i+1] && vp[i+1] > 0){
                vp[i+1]--;
                ans++;
            }
        }
        return ans;
        
    }
};