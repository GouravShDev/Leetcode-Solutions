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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode* ,long long>> q;
        q.push({root, 1});
        long long ans = 0;
        while(!q.empty()){
            int sz = q.size();
            long long first = -1;
            long long last = -1;
            for(int i =0 ; i < sz; i++){
                auto nodeNum= q.front();
                q.pop();
                if(first == -1) first = nodeNum.second;
                last= nodeNum.second;
                auto node = nodeNum.first;
                if(node->left) q.push({node->left, ((nodeNum.second-first) * 2) });
                if(node->right) q.push({node->right, ((nodeNum.second-first) * 2 + 1) });
            }
            ans = max(ans, last - first);
        }
        return ans+1;
    }
};