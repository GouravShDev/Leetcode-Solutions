//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  void addInVector(vector<int> &oddVec, vector<int> &evenVec , int val){
      if(val & 1){
          oddVec.push_back(val);
      }else{
          evenVec.push_back(val);
      }
  }
    long long solve(int N, vector<int> &A, vector<int> &B) {
       long long ans = 0;
       sort(A.begin(), A.end());
       sort(B.begin(), B.end());
       vector<int> oddA, evenA;
       vector<int> oddB, evenB;
       int i = 0;
       int j = 0;
       while(i < N|| j < N){
           if(i < N && j < N){
               if(A[i] == B[j]){
                   i++;
                   j++;
               }else if(A[i] > B[j]){
                   addInVector(oddB, evenB, B[j++]);
               }else{
                   addInVector(oddA, evenA, A[i++]);
               }
           }else if(i < N){
                addInVector(oddA, evenA, A[i++]);
           }else{
                addInVector(oddB, evenB, B[j++]);
           }
       }
       if(oddA.size() != oddB.size() || (evenA.size() != evenB.size())) return -1;
       long long incOp = 0;
       long long decOp = 0;
       for(int i  = 0 ; i < oddA.size() ; i++){
           int count = abs(oddA[i] - oddB[i])/2;
           if(oddA[i] > oddB[i]){
               decOp+= count;
           }else{
               incOp += count;
           }
       }
       
       for(int i  = 0 ; i < evenA.size() ; i++){
           int count = abs(evenA[i] - evenB[i])/2;
           if(evenA[i] > evenB[i]){
               decOp+= count;
           }else{
               incOp += count;
           }
       }
       if(incOp != decOp) return -1;
       return incOp;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends