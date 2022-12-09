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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        TreeNode* node1 = root1;
        TreeNode* node2 = root2;
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        while(node1 || node2 || !stk1.empty() || !stk2.empty()){
            if(!node1 && !stk1.empty()){
                node1= stk1.top()->right;
                stk1.pop();
            }
            if(!node2 && !stk2.empty()){
                node2 = stk2.top()->right;
                stk2.pop();
            }
            while(node1 && (node1->left || node1->right)){
               // stk1.push(node1);
                if(node1->left){                    if(node1->right) stk1.push(node1) ;

                    node1 = node1->left;
                }else{
                    node1 = node1->right;
                }
            }
            while(node2 && (node2->left || node2->right)){
                //stk2.push(node2);
             //   cout<<node2->val<<" " ;
                if(node2->left){                    if(node2->right) stk2.push(node2);

                    node2 = node2->left;
                }else{
                    node2 = node2->right;
                }
            }
         
            if(!node1 || !node2) return node1 == node2;
           // cout<<node1->val<<" "<<node2->val<<endl;
          if(node1->val != node2->val) return false;
            node1= node1->left;
            node2 = node2->left;
        }
        return node1 == node2;
    }
};