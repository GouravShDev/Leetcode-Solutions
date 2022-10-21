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
    bool solve(ListNode* node, ListNode* &head){
        if(!node) return true;
        bool ans = solve(node->next, head);
        if(node->val != head->val) return false;
        head= head->next;
        return ans;
    }
    bool isPalindrome(ListNode* head) {
        return solve(head, head);
    }
};