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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry= 0;
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        ListNode dummy(0);
        ListNode* p = &dummy;
        while(node1 || node2 || carry){
            int sum = carry;
            if(node1) sum+= node1->val;
            if(node2) sum+= node2->val;
            carry = sum/10;
            
            sum %= 10;
            // p ->next = new ListNode(sum);
            // p= p->next;
            if(node1){
                node1->val = sum;
                p->next = node1;
            }else if(node2){
                node2->val = sum;
                p->next = node2;
            }else{
                ListNode* newNode= new ListNode(sum);
                p->next = newNode;
            }
            p = p->next;
            if(node1){
                node1 = node1->next;
            }
            if(node2){
                node2 = node2->next;
            }
        }
        return dummy.next;
    }
};