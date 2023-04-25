class SmallestInfiniteSet {
public:
    set<int> st;
    SmallestInfiniteSet() {
        st.insert(INT_MAX);
    }
    
    int popSmallest() {
        for(int i = 1; i <= 1000; i++){
            if(!st.count(i)){
                st.insert(i);
                return i;
            }
        }
        return 0;
    }
    
    void addBack(int num) {
        st.erase(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */