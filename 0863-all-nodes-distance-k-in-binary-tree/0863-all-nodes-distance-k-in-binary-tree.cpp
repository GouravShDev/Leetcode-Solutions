/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, TreeNode*> parentPointer;
    void solve(TreeNode* node, TreeNode* parent){
        if(!node) return;
        if(parent != NULL) parentPointer[node] = parent;
        solve(node->left , node);
        solve(node->right, node);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        solve(root, NULL);
        queue<TreeNode*> q;
        q.push(target);
        vector<int> ans;
        map<TreeNode*, int> visited;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0;i < sz; i++){
                auto node= q.front();
                q.pop();
                if(visited[node]) continue;
                if(k == 0){
                    ans.push_back(node->val);
                    continue;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(parentPointer[node]) q.push(parentPointer[node]);
                visited[node] = 1;
            }
            if(k ==0) return ans;
            k--;
            
        }
        return ans;
    }
}; 