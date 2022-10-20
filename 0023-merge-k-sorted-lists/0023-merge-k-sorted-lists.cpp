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
struct compare{
    bool operator()(const ListNode* l1, const ListNode* l2){
        return l1->val > l2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)return NULL;
        priority_queue<ListNode* , vector<ListNode*> , compare> pq;
        
        for(auto &lt : lists){
           if(lt) pq.push(lt);
        }
        if(pq.empty() ) return NULL;
        ListNode* ans = pq.top();
        pq.pop();
        if(ans->next) pq.push(ans->next);
        ListNode* tails = ans;
        while(!pq.empty()){
            tails->next = pq.top();
            pq.pop();
            tails = tails->next;
            if(tails->next) pq.push(tails->next);
        }
        return ans;
        
    }
};