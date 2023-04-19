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
    int ans = 0;
    void solve(TreeNode* node , bool lastRight, int len){
        if(!node) return ;
        ans = max(ans, len);
        solve(node->left, !lastRight, lastRight ? len + 1: 0);
        solve(node->right, !lastRight, lastRight ? 0 : len + 1);
        
        
    }
    int longestZigZag(TreeNode* root) {
        solve(root, false, 0);
        solve(root, true, 0);
        return ans;
    }
};