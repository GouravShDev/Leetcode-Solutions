class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
       int ans  = 0;
        map<int,int> mp;
        for(auto &task : tasks){
            mp[task]++;
        }
        for(auto &it:mp){
            int freq = it.second;
            while(freq >= 3 && freq != 4){
                freq-=3;
                ans++;
            }
            while(freq >= 2){
                freq-=2;
                ans++;
            }
            // cout<<freq<<endl;
            if(freq > 0) return -1;
        }
        return ans;
    }
};