class Node{
public:
    Node* next;
    int val;
    Node(int value){
        val = value;
        next = NULL;
    }
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int length = 0;
    MyLinkedList() {
        head = NULL;
        tail = NULL;
    }
    
    int get(int index) {
        if(index >= length) return -1;
        auto node = head;
        int count = 0;
        while(count < index){
            node= node->next;
            count++;
        }
        return node->val;
    }
    
    void addAtHead(int val) {
            auto newNode = new Node(val);
        if(!head){
            head = newNode;
            tail = head;
        }else{
            newNode->next = head;
            head = newNode;
        }
        //cout<<"009";
        length++;
    }
    
    void addAtTail(int val) {
            auto newNode = new Node(val);
        if(!tail){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        //cout<<"009";
        length++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > length) return;
        
        if(index == length){
            addAtTail(val);
            return;
        }
        if(index == 0){
            addAtHead(val);
            return;
        }
       // cout<<"009";
        length++;
        
        int count = 1;
        auto node = head;
        while(count < index){
            node = node->next;
            count++;
        }
        auto newNode = new Node(val);
        newNode->next = node->next;
        node->next = newNode;
        
    }
    
    void deleteAtIndex(int index) {
        auto nd = head;
        while(nd){
            cout<<nd->val<<" ";
            nd = nd->next;
        }
        if(index >= length) return;
        if(index == 0){
        length--;
            head = head->next;
            return;
        }
       int count = 1;
        auto node = head;
        while(count < index){
         count++;
            node= node->next;
        }
        if(index == length-1){
            tail = node;
            cout<<"da" << length<<endl;
            node->next;
        }
        else{
            node->next = node->next->next;
        }
        length--;
        // cout<<endl;
        // nd = head;
        // while(nd){
        //     cout<<nd->val<<" ";
        //     nd = nd->next;
        // }
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */