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
    // < max, min  > 
    int ans = INT_MAX;
    pair<int,int> solve(TreeNode* root){
        if(!root) return {0, INT_MAX};
        
        auto left = solve(root->left);
        auto right = solve(root->right);
        if(root->left) ans = min(ans,  root->val - left.first);
        if(root->right) ans = min(ans,   right.second - root->val);
        return {max(root->val , right.first) ,  min(root->val , left.second)};
    }
    int getMinimumDifference(TreeNode* root) {
        solve(root);
        return ans;
    }
};