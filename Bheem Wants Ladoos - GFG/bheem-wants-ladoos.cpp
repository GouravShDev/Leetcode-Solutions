//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    int solve(Node* node, Node* lastNode,int k, map<Node*, Node*> &parent){
        if(!node) return 0;
        if(k == -1) return 0;
        int left = node->left != lastNode ? solve(node->left, node, k-1, parent) : 0;
        int right = node->right != lastNode? solve(node->right, node, k-1, parent) : 0;
        int p = parent[node] != lastNode ? solve(parent[node] , node, k-1 , parent) : 0;
        
        return node->data + left + right + p;
    }
    void dfs(Node*node, Node* parent, map<Node*, Node*> &mp){
        if(!node) return ;
        mp[node] = parent;
        dfs(node->left, node, mp);
        dfs(node->right, node, mp);
    }
    int ans = -1;
    void find(Node* node, int target, int k, map<Node*, Node*> &parent){
        if(!node) return;
        if(node->data == target){
            //cout<<"fda";
            ans = solve(node, NULL, k , parent);
            return;
        }
        find(node->left, target, k, parent);
        find(node->right ,target , k , parent);
        
    }
    int ladoos(Node* root, int home, int k)
    {
        map<Node* , Node*> parent;
       dfs(root, NULL, parent); 
       find(root, home, k , parent);
       return ans;
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends