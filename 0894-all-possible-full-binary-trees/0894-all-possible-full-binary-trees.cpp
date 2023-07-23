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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n==1) return {new TreeNode(0)};
        if((n&1) == 0) return {};
        
        vector<TreeNode*> ans;
        for(int i = 1 ; i < n ; i++){
            auto left = allPossibleFBT(i);
            auto right = allPossibleFBT(n -i-1);
            for(auto l : left){
                for(auto r : right){
                    TreeNode* node = new TreeNode(0);
                    node->left = l;
                    node->right = r;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
};