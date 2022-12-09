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
    void solve(TreeNode* root, int minVal, int mxVal, int &ans){
        ans = max(ans, abs(minVal - mxVal));
        if(!root)return;
        solve(root->left, min(minVal , root->val) , max(mxVal , root->val),ans);
        solve(root->right, min(minVal, root->val), max(mxVal, root->val),ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, root->val , root->val, ans);
        return ans;
    }
};