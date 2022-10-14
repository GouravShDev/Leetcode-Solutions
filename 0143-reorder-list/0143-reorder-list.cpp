/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* reverseLL(ListNode* node){
            if(!node || !node->next) return node;
            ListNode* newHead = reverseLL(node->next);
            node->next->next = node;
            node->next = NULL;
            return newHead;
        }
        void reorderList(ListNode *head) {
            if(!head->next || !head->next->next) return ;
            ListNode* slow = head;
            ListNode* fast = head->next->next;
            while(fast && fast->next){
                fast = fast->next->next;
                slow = slow->next;
            }
            auto newHead = reverseLL(slow->next);
            
            while(head && newHead->next){
                auto temp = head->next;
                head->next = newHead;
                auto temp2 = newHead->next;
                newHead->next = temp;
                head = temp;
                newHead = temp2;
            }
            // return dummy.next;
        }
};