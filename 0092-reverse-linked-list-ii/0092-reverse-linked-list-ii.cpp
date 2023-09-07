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
    ListNode* reverse(ListNode* start , ListNode* end){
        if(start == end) return end;
        // cout<<"da";
        auto newHead = reverse(start->next, end);
        start->next->next = start;
        start->next = NULL;
        return newHead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left == right)  return head;
        ListNode* node = head;
        ListNode* prev = NULL;
        for(int i = 1 ; i < left ; i++){
            prev =node;
            node = node->next;    
        }
        ListNode* last = node;
        ListNode* temp;
        for(int i = left;i < right; i++){
            last = last->next;
        }
            temp = last->next;
        auto x = reverse(node, last);
        if(prev != NULL){
            prev->next = x;
            
        }
        node->next= temp;
        if(left == 1) return x;
        return head;
        
    }
};