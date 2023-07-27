//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        int leftChildLeafIndex = 2 * i + 1;
        if(leftChildLeafIndex >= n) return;
        bool leftLess = arr[leftChildLeafIndex] < arr[i];
        bool rightLess = false;
        int rightChildLeafIndex = 2 * i + 2;
        if(rightChildLeafIndex < n){
            rightLess = arr[rightChildLeafIndex] < arr[i];
        }
        if(leftLess && rightLess && arr[rightChildLeafIndex] < arr[leftChildLeafIndex]){
             swap(arr[i], arr[rightChildLeafIndex]);
            return heapify(arr, n , rightChildLeafIndex);
        }
        if(leftLess){
            swap(arr[i] , arr[leftChildLeafIndex]);
            return heapify(arr, n , leftChildLeafIndex);
        }
        if(rightLess){
            swap(arr[i], arr[rightChildLeafIndex]);
            return heapify(arr, n , rightChildLeafIndex);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        int i = (n / 2);
        while(i >= 0){
            heapify(arr , n , i);
            i--;
        }
    }
    void deletion(int arr[], int n){
        swap(arr[0], arr[n-1]);
        heapify(arr, n-1, 0);
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        // for(int i = 0 ;i < n ; i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        int temp[n];
        for(int i = 0; i < n ; i++){
            temp[i] = arr[0];
            deletion(arr, n- i);
        }
        for(int i = 0 ;i < n ; i++){
            arr[i] = temp[i];
        }
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends