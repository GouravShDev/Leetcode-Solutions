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
    TreeNode* assign(TreeNode* left , TreeNode* right, int index){
      TreeNode* node = new TreeNode(index);
        node->left = left;
        node->right = right;  
        return node;
    }
    vector<TreeNode*> solve(int l, int r){
        if(l  > r) return {NULL};
        vector<TreeNode*> ans;
        for(int index = l ;index <= r ; index++){
            auto lefts = solve(l, index -1);
            auto rights = solve(index + 1, r);
               for(auto &left : lefts){
                    for(auto &right : rights){
                        auto node = assign(left , right, index);
                        ans.push_back(node);
                    }
            }
            
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};