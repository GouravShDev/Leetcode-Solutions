class Solution {
public:
    int check(vector<int> &A, vector<int> &B, vector<int> &C){
        return (((B[0] - A[0]) * (C[1] - A[1])) - ((B[1] - A[1]) * (C[0] - A[0])) );
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if(trees.size() <= 3) return trees;
        sort(trees.begin() , trees.end());
        
        // upper hull
        vector<vector<int>> upperHull;
        upperHull.push_back(trees[0]);
        upperHull.push_back(trees[1]);
        
        for(int i = 2 ; i < trees.size() ; i++){
            int ls = upperHull.size();
            while(upperHull.size() >= 2 && check(upperHull[ls-2] , upperHull[ls-1], trees[i]) > 0){
                upperHull.pop_back();
                ls--;
            }
            upperHull.push_back(trees[i]);

        }
        
        // lowerHull
        vector<vector<int>> lowerHull;
        int n = trees.size();
        lowerHull.push_back(trees[n-1]);
        lowerHull.push_back(trees[n-2]);
        
        for(int i = trees.size()-3;  i >= 0; i--){
            int ls = lowerHull.size();
            while(lowerHull.size() >= 2 && check(lowerHull[ls-2], lowerHull[ls-1], trees[i] )>0){
                lowerHull.pop_back();
                ls--;
            }
            lowerHull.push_back(trees[i]);
        }
        vector<vector<int>> ans(upperHull.size() + lowerHull.size());
        merge(upperHull.begin(), upperHull.end(), lowerHull.begin(), lowerHull.end(), ans.begin());
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin() ,ans.end()), ans.end());
        return ans;
    }
    
};