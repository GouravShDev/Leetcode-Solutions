class Solution {
public:
    struct compare{
        bool operator()(pair<int,string> &a,pair<int,string>&b){
            if(a.first==b.first)
                return a.second<b.second;
            return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto &word : words){
            mp[word]++;
        }
        priority_queue<pair<int, string> , vector<pair<int,string>>, compare> pq;
        for(auto &it: mp){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        map<int, set<string>> mpp;
        for(int i = k-1; i >= 0; i--){
            mpp[pq.top().first].insert( pq.top().second);
            pq.pop();
        }
        vector<string> ans;
        for(auto it = mpp.rbegin(); it != mpp.rend(); it++){
            ans.insert(ans.end(), it->second.begin() ,it->second.end());
        }
        return ans;
    }
};