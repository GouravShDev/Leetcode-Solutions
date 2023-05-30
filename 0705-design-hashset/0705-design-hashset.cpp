class MyHashSet {
public:
    int arr[1000000+1];
    MyHashSet() {
        
    }
    
    void add(int key) {
        arr[key] = 1;
    }
    
    void remove(int key) {
        if(arr[key]){
            arr[key] = 0;
        }
    }
    
    bool contains(int key) {
        return arr[key] == 1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */