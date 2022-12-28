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
    int solve(TreeNode* node,long long sum, int targetSum){
        if(!node) return 0;
        sum += node->val;
        int left = solve(node->left, sum , targetSum);
        int right = solve(node->right, sum , targetSum);
        return (sum == targetSum) + left+ right;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        
        int leftB = pathSum(root->left, targetSum);
        int rightB = pathSum(root->right, targetSum);
        return solve(root , 0, targetSum) + leftB + rightB;
    }
};