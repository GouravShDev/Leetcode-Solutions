/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void dfs(Node* node){
        if(!node|| !node->left) return ;
        
        if(node->next){
            node->right->next = node->next->left;
        }
        node->left->next = node->right;
        dfs(node->left);
        dfs(node->right);
    }
    Node* connect(Node* root) {
        dfs(root);
        return root;
    }
};