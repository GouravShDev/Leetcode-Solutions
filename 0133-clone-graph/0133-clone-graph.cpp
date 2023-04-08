/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node*  connectDfs(Node *orgNode, set<Node*> &visited, map<Node*, Node*> &mp){
        visited.insert(orgNode);
        Node* cloneNode = mp[orgNode];
        for(auto &adj : orgNode->neighbors){
            if(visited.count(adj)){
                // cout<<orgNode->val<<endl;
                cloneNode->neighbors.push_back(mp[adj]);
                continue;
            }
            cloneNode->neighbors.push_back(connectDfs(adj, visited, mp));
        }
        return cloneNode;
    }
        
    void dfs(Node* node,set<Node*> &visited, map<Node*, Node*> &mp){
        visited.insert(node);
        mp[node] = new Node(node->val);
        
        for(auto &adj : node->neighbors){
            if(visited.count(adj)) continue;
            dfs(adj , visited, mp);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        map<Node*, Node*> mp;
        set<Node*> vis1;
        set<Node*> vis2;
        dfs(node, vis1, mp);
        return connectDfs(node, vis2, mp);
    }
};