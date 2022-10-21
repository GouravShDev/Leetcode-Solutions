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
    ListNode* getMiddle(ListNode* node){
        if(!node) return NULL;
        ListNode* slow = node;
        ListNode* fast = node;
        while(fast && fast->next){
            slow = slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
    bool solve(ListNode* head, ListNode* &node){
        if(!head)return true;
        bool ans = solve(head->next, node);
        if(head->val  != node->val) return false;
        node = node->next;
        return ans;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* middle = getMiddle(head);
        return solve(middle, head);
    }
};