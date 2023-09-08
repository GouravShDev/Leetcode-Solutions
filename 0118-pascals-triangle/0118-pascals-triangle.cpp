class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> ans;
        vector<int> cur;
        for(int i = 0;  i < numRows; i++){
            // cout<<i<<endl;
            int prev = 1;
            for(int j = 1 ; j < cur.size(); j++){
                auto x = cur[j] + prev;
                prev = cur[j];
                cur[j] = x;
            }
            cur.push_back(1);
            ans.push_back(cur);
        }
        return ans;
    }
};