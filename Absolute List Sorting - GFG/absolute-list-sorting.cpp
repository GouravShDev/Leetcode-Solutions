//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
	Node* next;
	int data;
};

// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
	Node* newNode = new Node;
	newNode->next = (*head);
	newNode->data = data;
	(*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL)
	{
		cout << head->data;
		if (head->next != NULL)
			cout << " ";
		head = head->next;
	}
	cout << endl;
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
class Solution{
    
public:
    Node* reverse(Node *node){
        if(!node->next)return node;
        Node *newHead = reverse(node->next);
        node->next->next = node;
        node->next = NULL;
        return newHead;
    }
    Node* sortList(Node* head)
    {
        Node pHead;
        Node nHead;
        Node* posNode = &pHead;
        Node* negNode = &nHead;
        Node* node = head;
        while(node){
            if(node->data < 0){
                negNode->next = node;
                negNode = negNode->next;
            }else{
                posNode->next = node;
                posNode= posNode->next;
            }
            node = node->next;
        }
        posNode->next = NULL;
        negNode->next = NULL;
        if(nHead.next){
        Node* sortedListHead  = reverse(nHead.next);
        nHead.next->next = pHead.next;
        return sortedListHead;
        }
        return pHead.next;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{

	int t = 0;
	int n = 0;
	cin >> t;
	while (t--)
	{
		Node* head = NULL;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			// push(&head, a);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			push(&head, arr[i]);
		}
		// printList(head);
		
		Solution ob;
		head=ob.sortList(head);

		printList(head);

	}
	return 0;
}

// } Driver Code Ends