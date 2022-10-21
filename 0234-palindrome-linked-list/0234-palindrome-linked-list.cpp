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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast= head;
        ListNode* prev = NULL;
        while(fast && fast->next){
            fast = fast->next->next;
            ListNode* temp = slow->next;
            slow->next = prev;
            prev= slow;
            slow = temp;    
        }
        auto rvHead = prev;
        prev = slow;
        if(fast) slow= slow->next;
        auto midHead = slow;
        bool isPalindrome=true;
        while(rvHead && midHead){
            if(rvHead->val != midHead->val) isPalindrome =  false;
            // restoring original list
            ListNode* temp = rvHead->next;
            rvHead->next = prev;
            prev = rvHead;
            rvHead = temp;
            midHead = midHead->next;
        }
        
        return isPalindrome;
    }
};