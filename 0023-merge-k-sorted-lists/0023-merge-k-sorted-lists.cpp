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
    struct compare{
        bool operator ()(ListNode* l1, ListNode* l2){
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return NULL;
        priority_queue<ListNode*,vector<ListNode*>, compare> pq;
        for(auto &head : lists){
            if(head) pq.push(head);
        }
        
        ListNode newHead(0);
        ListNode* ptr = &newHead;
        while(!pq.empty()){
            auto node= pq.top();
            pq.pop();
            ptr->next = node;
            ptr = ptr->next;
            if(node->next) pq.push(node->next);
        }
        return newHead.next;
        
    }
};