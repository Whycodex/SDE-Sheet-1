//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here
            int arr[n+m];
            int i=0,j=0,k=0;
            while(i<n&&j<m){
                if(arr1[i]<=arr2[j]){
                    arr[k]=arr1[i];
                    i++;
                    k++;
                }
                else{
                    arr[k]=arr2[j];
                    j++;
                    k++;
                }
            }
            while(i<n){
                arr[k]=arr1[i];
                i++;
                k++;
            }
            while(j<m){
                arr[k]=arr2[j];
                j++;
                k++;
            }
            int ind=0,temp=0;
            while(ind<n){
                arr1[temp]=arr[ind];
                temp++;
                ind++;
            }
            ind=0;
            while(ind<m){
                arr2[ind]=arr[temp];
                temp++;
                ind++;
            }
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends