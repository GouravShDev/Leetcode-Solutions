//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int mxDead = -1;
        for(int i = 0; i< n ;i++){
            if(arr[i].dead > mxDead){
                mxDead = arr[i].dead;
            }
        }
        sort(arr , arr+ n , [] (Job &j1, Job &j2){
           return j1.profit > j2.profit; 
        });
        vector<int> slots(mxDead);
        int ans = 0;
        int count = 0;
        for(int i = 0 ; i< n ; i++){
            int dead = arr[i].dead - 1;
            while(dead >= 0 && slots[dead]){
                dead--;
            }
            if(dead >= 0 && !slots[dead]){
                count++;
                slots[dead] = 1;
                ans+= arr[i].profit;
            }
        }
        return {count , ans};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends