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
        stack<ListNode*> stk1;
        stack<ListNode*> stk2;
        while(l1 || l2){
            if(l1) {
                stk1.push(l1);
                l1 = l1->next;
            }
            if(l2){
                stk2.push(l2);
                l2 = l2->next;
            }
        }
        stack<ListNode*> stk;
        int carry = 0;
        int sum = 0;
        while(!stk1.empty() || !stk2.empty()){
            ListNode* l1;
            ListNode* l2;
            sum = carry;
            if(!stk1.empty()){
                l1 = stk1.top();
                stk1.pop();
                sum += l1->val;
            }
            if(!stk2.empty()){
                l2 = stk2.top();
                stk2.pop();
                sum += l2->val;
            }
            carry = sum/ 10;
            stk.push(new ListNode(sum%10));
        }
        if(carry)
            stk.push(new ListNode(1));
        ListNode* node = new ListNode();
        ListNode* ans = node;
        while(!stk.empty()){
            node->next = stk.top();
            stk.pop();
            node = node->next;
        }
        return ans->next;
    }
};