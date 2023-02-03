//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    long long int res=0;
	    sort(arr,arr+n);
	    for(int i=0;i<n-2;i++){
	        int front=i+1;
	        int back=n-1;
	        while(front<back){
	            if(arr[i]+arr[front]+arr[back]<sum){
	                res+=(back-front);
	                front++;
	            }
	            else{
	                back--;
	            }
	        }
	    }
	    return res;
	}
		 

};

//{ Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends