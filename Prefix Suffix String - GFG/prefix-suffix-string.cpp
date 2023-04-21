//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Node{
    
    vector<Node*> links;
    
    bool isEnd = false;
    public:
    Node(){
        links.resize(26, NULL);
    }
    bool getEnd(){
        return isEnd;
    }
    void setEnd(bool val){
         isEnd = val;
         return;
    }
    void setLink(char c){
        links[c - 'a'] = new Node();
    }
    Node* getLink(char c){
        return links[c - 'a'];
    }
};
class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for(int i =0 ; i < word.size(); i++){
            char c = word[i];
            if(node->getLink(c) == NULL){
                node->setLink(c);
            }
            node = node->getLink(c);
        }
    }
    bool check(string word){
        Node* node = root;
        for(int i=0 ;i < word.size() ;i++){
            char c = word[i];
            if(node->getLink(c) == NULL) return false;
            node= node->getLink(c);
        }
        return true;
    }
};
class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        Trie *trie = new Trie();
        for(auto s: s1){
            trie->insert(s);
             reverse(s.begin(), s.end());
            trie->insert(s);
        }
        int ans = 0 ;
        for(auto s : s2){
            string v = s;
            reverse(v.begin(), v.end());
            if(trie->check(s) || trie->check(v)){
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends