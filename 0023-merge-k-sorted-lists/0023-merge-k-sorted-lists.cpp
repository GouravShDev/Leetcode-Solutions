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
    ListNode* mergeTwoLL(ListNode* l1, ListNode* l2){
        ListNode newHead(0);
        ListNode* p = &newHead;
        while(l1 || l2){
            if(l1 && l2){
                if(l1->val < l2->val){
                    p->next= l1;
                    l1 = l1->next;
                }else{
                    p->next = l2;
                    l2 = l2->next;
                }
            }else{
                if(l1){
                    p->next = l1;
                    l1= l1->next;
                }else{
                    p->next = l2;
                    l2= l2->next;
                }
            }
            p = p->next;
        }
        return newHead.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        int k = 0;
        vector<ListNode*> lts= lists;
        while(lts.size() != 1){
            int n = lts.size()-1;
            vector<ListNode*> ls;
            k = 0;
            while(k <(lts.size()+1)/2){
                // cout<<k<<endl;
                auto s = (k == lts.size()/2 )? NULL: lts[n-k];
                ls.push_back(mergeTwoLL(lts[k], s));
                k++;
            }
            // cout<<ls.size()<<endl;
            lts = ls;
        }
        // cout<<"adf";
        // return NULL;
        return lts.back();
    }
};