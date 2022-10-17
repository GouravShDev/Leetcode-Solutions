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
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd(0);
        ListNode even(0);
        ListNode* oddPointer = & odd;
        ListNode* evenPointer = &even;
        int count = 0;
        ListNode* node = head;
        while(node){
            if(count&1){
                oddPointer->next = node;
                oddPointer = oddPointer->next;
            }else{
                evenPointer->next = node;
                evenPointer = evenPointer->next;
            }
            count++;
            node= node->next;
        }
        evenPointer->next = odd.next;
        oddPointer->next=  NULL;
        return even.next;
    }
};