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
    ListNode* partition(ListNode* head, int x) {
       ListNode node1 =  ListNode(0);
        ListNode node2 = ListNode(0);
        auto d1 = &node1;
        auto d2 = &node2;
        while(head){
            if(head->val < x){
                d1->next = head;
                d1 = head;
            }else{
                d2->next = head;
                d2= head;
            }
            head = head->next;
        }
        d1->next = NULL;
        d2->next = NULL;
        if(node1.next){
            d1->next = node2.next;
            return node1.next;
        }
        return node2.next;
    }
};