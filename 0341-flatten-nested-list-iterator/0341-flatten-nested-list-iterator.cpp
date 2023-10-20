/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList();
 * };
 */

class NestedIterator {
public:
    vector<int> ans;
    int index = 0;
    void solve(vector<NestedInteger> &nestedList){
         for(auto it : nestedList){
            if(it.isInteger()){
                ans.push_back(it.getInteger());
            }else{
                solve(it.getList());   
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
       solve(nestedList);
    }
    
    int next() {
        return ans[index++];
    }
    
    bool hasNext() {
        if(index == ans.size()) return false;
        return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */