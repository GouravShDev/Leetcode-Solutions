typedef  map<string, vector<string>> gg;
class Solution {
    int n;
public:
    bool solve(string from, gg &graph, map<pair<string,string>, int> &mp, vector<string> &ans)
    {

        if(ans.size() == n)
        {
            return true;
        }
        for(auto  to: graph[from])
        {
            if(mp[{from, to}]<=0) continue;
            mp[{from, to}] -= 1;
            ans.push_back(to);
            if(solve(to, graph, mp, ans)) return true;
            ans.pop_back();
            mp[{from, to}] +=1;
        }
        
        return false;
    }
    
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        n = tickets.size() + 1;
        gg graph;
        map<pair<string,string>, int> cnt;
        for(auto t: tickets)
        {
            string from = t[0];
            string to = t[1];
            cnt[{from,to}]++;
            graph[from].push_back(to);
        }
        
        for(auto &v: graph)
        {
            sort(v.second.begin(), v.second.end());
        }
        
        vector<string>  ans;
        ans.push_back("JFK");
        solve("JFK", graph, cnt, ans );
        return ans;
    }
};