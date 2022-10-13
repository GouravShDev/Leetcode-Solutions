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
    int dfs(TreeNode* node, int &k){
        if(!node)return -1;
        int left =dfs(node->left, k);
        if(left!= -1) return left;
        if(k-- == 1) return node->val;
        int right = dfs(node->right, k);
        return right;
    }
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root, k);
    }
};