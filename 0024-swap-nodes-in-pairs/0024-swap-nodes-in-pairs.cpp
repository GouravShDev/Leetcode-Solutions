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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* nxtNode = head->next;
        ListNode* curNode = head;
        ListNode* temp = nxtNode->next;
        nxtNode->next = curNode;
        curNode->next = swapPairs(temp);
        return nxtNode;
        
    }
};