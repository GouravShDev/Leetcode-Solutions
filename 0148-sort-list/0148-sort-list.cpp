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
    ListNode* mergeTwoSortedLL(ListNode* head1, ListNode* head2){
        ListNode* newHead = new ListNode();
        ListNode* nHead = newHead;
        while(head1 || head2){
            if(head1 && head2){
                if(head1->val < head2->val){
                    newHead->next = head1;
                    head1 = head1->next;
                }else{
                    newHead->next = head2;
                    head2= head2->next;
                }
            }else if(head1){
                newHead->next = head1;
                head1= head1->next;
            }else{
                newHead->next = head2;
                head2 = head2->next;
            }
            newHead = newHead->next;
        }
        return nHead->next;
    }
    
    ListNode* getMiddle(ListNode *head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return prev;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* middle = getMiddle(head);
        
        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;
        middle->next = NULL;
        //cout<<leftHead->val<<endl;
         leftHead =sortList(leftHead);
         rightHead =sortList(rightHead);
        return mergeTwoSortedLL(leftHead, rightHead);
    }
};