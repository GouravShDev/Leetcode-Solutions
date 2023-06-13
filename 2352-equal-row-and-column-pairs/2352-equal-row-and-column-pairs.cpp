class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        map<vector<int>,int> r,c;
        int ans=0;
        for(auto x: grid)
        {
            vector<int> v;
            for(auto y:x)v.push_back(y);
            r[v]++;
        }
        for(int i=0;i<n;i++)
        {
            vector<int> v;
            for(int j=0;j<n;j++)
            {
                v.push_back(grid[j][i]);
            }
            c[v]++;
            if(r.find(v)!=r.end())ans+=r[v];
        }
        return ans;
    }
};