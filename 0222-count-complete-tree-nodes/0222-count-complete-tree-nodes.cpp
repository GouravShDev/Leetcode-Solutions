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
    int getHeightR(TreeNode* node){
        if(!node)return 0;
        return 1 + getHeightR(node->right);
    }
    int getHeightL(TreeNode* node){
        if(!node) return 0;
        return 1 + getHeightL(node->left);
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int leftHeight = getHeightL(root);
        int rightHeight = getHeightR(root);
        if(leftHeight == rightHeight){
            return pow(2, leftHeight) - 1;
        }else{
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};