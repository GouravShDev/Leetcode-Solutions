/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* node1 = head;
        ListNode* node2 = head;
        int x = k-1;
        while(x){
            node1 = node1->next;
            x--;
        }
        x = k-1;
        ListNode* temp = node1;
        while(temp->next){
            temp= temp->next;
            node2 = node2->next;
        }
        swap(node1->val , node2->val);
        return head;
    }
    
};