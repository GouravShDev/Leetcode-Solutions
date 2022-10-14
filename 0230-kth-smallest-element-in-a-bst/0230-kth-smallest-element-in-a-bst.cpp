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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while(node || !stk.empty()){
            if(node){
                stk.push(node);
                node= node->left;
            }else{
                node = stk.top();
                stk.pop();
                if(k == 1){
                    return node->val;
                }
                k--;
                node = node->right;
            }
        }
        return -1;
    }
};