class Node{
public:
    bool isEnd;
    Node** links;
    
    Node(){
        links = new Node*[26]();
        isEnd = false;
    }
    bool getEnd(){
        return isEnd;
    }
    Node* getLink(char c){
        return links[c-'a'];
    }
    void setLink(char c){
        links[c-'a'] = new Node();
    }
    void setEnd(bool v){
        isEnd = v;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        int n = word.size();
        for(int i =0 ; i < n ; i++){
            if(node->getLink(word[i])== NULL){
                node->setLink(word[i]);
            }
            node = node->getLink(word[i]);
        }
        node->setEnd(true);
    }
    
    bool search(string word) {
        Node *node = root;
        int n= word.size();
        for(int i = 0; i < n ; i++){
            if(node->getLink(word[i]) == NULL) return false;
            node = node->getLink(word[i]);
        }
        return node->getEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        int n= prefix.size();
        for(int i = 0; i < n ; i++){
            if(node->getLink(prefix[i]) == NULL) return false;
            node = node->getLink(prefix[i]);
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */