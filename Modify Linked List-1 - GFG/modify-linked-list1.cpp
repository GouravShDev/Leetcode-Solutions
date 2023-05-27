//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
  
struct Node* reverseLinkedList(struct Node* head) {
    struct Node* prev = nullptr;
    struct Node* curr = head;
    struct Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
    struct Node* modifyTheList(struct Node *head)
    {
        Node* slow = head;
        Node* fast = head->next;
        while(fast && fast->next){
            fast= fast->next->next;
            slow = slow->next;
        }
        //cout<<slow->data<<endl;
        slow->next = reverseLinkedList(slow->next);
        //cout<<slow->next->data<<endl;
        auto n1 = head;
        auto n2 = slow->next;
        
        while(n1 && n2){
            int dif = n2->data - n1->data;
            n2->data = n1->data;
            n1->data = dif;
            n1 = n1->next;
            n2 = n2->next;
        }
        auto temp = head;
        // cout<<endl;
        
        slow->next = reverseLinkedList(slow->next);
        
        // while(temp){
        //     cout<<temp->data<<" ";
        //     temp = temp->next;
        // }
        // cout<<endl;
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends