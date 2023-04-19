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
    int solve(TreeNode* node, bool isLastRight){
        if(!node) return -1;
        int left = 1 + solve(node->left, false);
        int right = 1 + solve(node->right, true);
        ans = max({ans, right, left});
        return isLastRight? left : right;
    }
    int longestZigZag(TreeNode* root) {
       
        solve(root, true);
        return ans;
    }
};