//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int>v;
    int ind=lower_bound(arr,arr+n,x)-arr;
    if(ind!=n&&arr[ind]==x){
        v.push_back(ind);
    }
    else{
        v.push_back(-1);
    }
    ind=upper_bound(arr,arr+n,x)-arr;
    ind--;
    if(ind>=0&&arr[ind]==x){
        v.push_back(ind);
    }
    else{
        v.push_back(-1);
    }
    return v;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends