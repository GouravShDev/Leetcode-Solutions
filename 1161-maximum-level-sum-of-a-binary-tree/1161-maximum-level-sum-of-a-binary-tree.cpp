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
    int maxLevelSum(TreeNode* root) {
        int ans = 0;
        int ansMx = INT_MIN;
        int curLevel;
        int lvl = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            curLevel = 0;
            for(int i =0 ; i < sz; i++){
                auto node = q.front();
                q.pop();
                curLevel+= node->val; 
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(curLevel > ansMx){
                ansMx = curLevel;
                ans = lvl;
            }
            lvl++;
        }
        return ans;
    }
};