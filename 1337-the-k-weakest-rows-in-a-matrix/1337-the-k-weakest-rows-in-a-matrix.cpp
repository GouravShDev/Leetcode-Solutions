
class Compare
{
public:
    bool operator() (pair<int,vector<int>> &a, pair<int,vector<int>> &b)
    {
        int aCount = accumulate(a.second.begin(), a.second.end(), 0);
        int bCount = accumulate(b.second.begin(), b.second.end(), 0 );
        if(aCount == bCount) return a.first < b.first;
        return aCount < bCount;
    }
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>> , Compare> pq;
        vector<int> ans;
        for(int i =0 ; i < mat.size() ;i++){
            pq.push({i, mat[i]});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;;
    }
};