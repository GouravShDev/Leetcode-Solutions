class Node{
public:
    bool isEndNode;
    Node** links;
    
    Node(){
        links = new Node*[26]();
        isEndNode = false;
    }
    ~Node(){
        delete[] links;
    }
    bool isEnd(){
        return isEndNode;
    }
    Node* get(char c){
        return links[c-'a'];
    }
    bool contains(char c){
        return links[c-'a'] != NULL;
    }
    void put(char c){
        links[c-'a'] = new Node();
    }
    void setEnd(bool v = true){
        isEndNode = v;
    }
};

   void insert(string word, Node* root) {
        Node* node = root;
        for(int i =0 ; i < word.size(); i++){
            if(node->contains(word[i])== NULL){
                node->put(word[i]);
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
class Solution {
public:
    bool dfs(string &word, int startingInd, Node* root){
        if(startingInd == word.size())return true;
        Node* node = root;
        for(int i = startingInd ; i < word.size() ; i++){
            //cout<<word[i]<<" ";
            if(node->contains(word[i]) == NULL){
                return false;
            }
            
            node = node->get(word[i]);
            
            if(node->isEnd()){
                if(dfs(word, i+1, root)){
                    return true;
                }
            }
        }
        return node->isEnd();
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin() , words.end(), [](auto w1, auto w2){
           if(w1.size() == w2.size()){
               return w1 < w2;
           }
            return w1.size() < w2.size();
        });
        // for(auto &w : words){
        //     cout<<w<<endl;
        // }
        Node* root = new Node();
        vector<string> ans;
        for(int i = 0 ; i< words.size(); i++){
           // cout<<i<<" ";
            if(dfs(words[i], 0 , root)){
                ans.push_back(words[i]);
            }
            insert(words[i], root);
        }
        return ans;
    }
};