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
        int length = lists.size();
        while(length != 1 ){
            
            k = 0;
            while(k < length / 2){
                // cout<<k<<endl;
                lists[k] = mergeTwoLL(lists[k], lists[length - k - 1]);
                k++;
            }
            // cout<<ls.size()<<endl;
            length = (length + 1)/ 2;
        }
        // cout<<"adf";
        // return NULL;
        return lists.front();
    }
};