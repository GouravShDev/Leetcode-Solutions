class Node{
    public:
    Node* next;
    Node* prev;
    int val;
    Node(int value){
        val = value;
        next = NULL;
        prev = NULL;
    }
};
class DoublyLinkedList{
public:
    Node* head;
    Node* tails;
    
    DoublyLinkedList(){
        head = NULL;
        tails = NULL;
    }
    void addToHead(int val){
        auto newHead = new Node(val);
        if(!head){
            head = newHead;
            tails = newHead;
        }else{
            newHead->next = head;
            head->prev = newHead;
            head = newHead;
        }
    }
    // void addToTail(int val){
    //     auto newTail = new Node(val);
    //     if(!tails){
    //         head = newTail;
    //         tails = newTail; 
    //     }else{
    //         tails->prev = newTail;
    //         newTail->next = tails;
    //         tails = newTail;
    //     }
    // }
    void deleteNode(Node* node){
        auto prev = node->prev;
        auto next = node->next;
        if(prev) prev->next = next;
        if(next) next->prev = prev;
        if(node == head){
            head = next;
        }
        if(node == tails){
            tails = prev;
        }
        delete node;
    }
};
class LRUCache {
public:
    int size = 0;
    int maxSize;
    DoublyLinkedList* ddl;
    map<int, Node*> mp;
    map<Node*, int> revMp;
    LRUCache(int capacity) {
        maxSize = capacity;
        ddl = new DoublyLinkedList();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        int value = mp[key]->val;
            revMp.erase(mp[key]);
        ddl->deleteNode(mp[key]);
        ddl->addToHead(value);
        mp[key] = ddl->head;
        revMp[ddl->head] = key;
        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            // found
            revMp.erase(mp[key]);
            ddl->deleteNode(mp[key]);
            ddl->addToHead(value);
            mp[key] = ddl->head;
            revMp[ddl->head] = key;
            
        }else{
            // not found
            if(size == maxSize){
                // sizeoverflow
                int k = revMp[ddl->tails];
                // cout<<k<<" "<<ddl->tails->val<<endl;
                mp.erase(k);
                revMp.erase(ddl->tails);
                ddl->deleteNode(ddl->tails);
                size--;
            }
            ddl->addToHead(value);
            mp[key] = ddl->head;
            revMp[ddl->head] = key;
            size++;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */