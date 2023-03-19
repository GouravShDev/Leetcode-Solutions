class Node{
public:
    bool isEnd;
    Node** links;
    
    Node(){
        links = new Node*[26]();
        isEnd = false;
    }
    ~Node(){
        delete[] links;
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
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
        
    }
    
    void addWord(string word) {
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
    bool search(string word, int index, Node* node){
        if(!node) return false;
        if(index == word.size()) return node->getEnd();
        if(word[index] == '.'){
            for(int i = 0 ; i < 26 ; i++){
                if(node->getLink('a' + i) ==  NULL )continue;
                if(search(word, index+1, node->getLink('a' + i))) return true;
            
            }
            return false;
        }
        if(node->getLink(word[index]) ==  NULL) return false;
        return search(word, index+1, node->getLink(word[index]));
    }
    bool search(string word) {
        return search(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */