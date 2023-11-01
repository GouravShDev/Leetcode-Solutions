/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* node, map<int,int> &mp){
        if(!node) return;
           solve(node->left , mp);
        mp[node->val]++;
           solve(node->right , mp);
     
    }
    vector<int> findMode(TreeNode* root) {
        map<int,int> mp;
        solve(root, mp);
        vector<int> ans;
        int mx = 0;
        for(auto &it : mp){
            if(mx < it.second) mx = it.second;
        }
        for(auto &it : mp){
            if(it.second == mx) ans.push_back(it.first);
        }
        return ans;
    }
};