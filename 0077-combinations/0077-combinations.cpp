class Solution {
public:
    void solve(int i , int n , int k, vector<int> &path, vector<vector<int>> &ans){
        if(path.size() > k) return;
        if(path.size() == k){
            ans.push_back(path);
            return;
        }
        if(i > n) return;
        // Ignore
        solve(i+1, n , k , path , ans);
       
        // Add
        path.push_back(i);
        solve(i+1, n , k , path , ans);
        path.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(1, n, k , path, ans);
        return ans;
    }
};