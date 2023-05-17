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
    ListNode* fast;
    ListNode* slow;
    ListNode* prev;
    int ans = 0;
    void solve(ListNode* node1, ListNode* &node2){
        if(!fast || !fast->next){
            node2 = node1;
            return;
        }
        fast = fast->next->next;
        solve(node1->next, node2);
        //cout<< node1->val<<" "<<node2->val<<endl;
        ans = max(ans,node1->val+ node2->val);
        node2 = node2->next;
    }
    int pairSum(ListNode* head) {
        fast = head;
        solve(head, head);
        return ans;
    }
};