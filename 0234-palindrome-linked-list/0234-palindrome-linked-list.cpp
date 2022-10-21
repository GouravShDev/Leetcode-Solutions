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
    pair<ListNode*, ListNode*> getMiddleAndPrev(ListNode* node){
        if(!node) return {NULL, NULL};
        ListNode* slow = node;
        ListNode* fast = node;
        ListNode* prev= NULL;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast= fast->next->next;
        }
        return {prev, slow};
    }
    ListNode* reverseLL(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* newHead = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        auto [middlePrev , middle] = getMiddleAndPrev(head);
        ListNode* rvHead = reverseLL(middle);
        auto reverseHead = rvHead;
        ListNode* orgHead = head;
        while(head && reverseHead){
            if(head->val != reverseHead->val){
                return false;
            }
            head = head->next;
            reverseHead=  reverseHead->next;
        }
        // ListNode* rvvHead = reverseLL(rvHead);
        // middlePrev ->next = rvvHead;
        // while(orgHead){
        //     cout<<orgHead->val<<" ";
        //     orgHead=orgHead->next;
        // }
        return true;
        
    }
};