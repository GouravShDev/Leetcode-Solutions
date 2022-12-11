/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        Node* node = head;
        
        while(node){
            Node* nd = new Node(node->val);
            Node* temp = node->next;
            node->next = nd;
            nd->next = temp;
            node = temp;
        }
        node= head;
        Node* newNode = node->next;
        Node* ans = newNode;
        while(newNode){
            newNode->random = node->random ?  node->random->next : NULL;
            newNode = newNode->next ? newNode->next->next : NULL;
            node = node->next ? node->next->next : NULL;
        }
        node = head;
        newNode = ans;
        while(node){
            Node* temp = newNode->next;
            node->next = node->next->next;
            newNode->next = temp ? temp->next : NULL;
            node = node->next;
            newNode= newNode->next;
        }
        // while(ans){
            // cout<<ans->val<<" ";
        //     ans = ans->next;
        // }
        return ans;
    }
};