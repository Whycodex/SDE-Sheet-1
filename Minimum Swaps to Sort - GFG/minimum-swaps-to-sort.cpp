//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    unordered_map<int,int>m;
	    for(int i=0;i<nums.size();i++){
	        m[nums[i]]=i;
	    }
	    int res=0;
	    vector<int>temp=nums;
	    sort(temp.begin(),temp.end());
	    for(int i=0;i<nums.size();i++){
	        if(nums[i]!=temp[i]){
	            res++;
	            int t=nums[i];
	            swap(nums[i],nums[m[temp[i]]]);
	            m[t]=m[temp[i]];
	            m[temp[i]]=i;
	        }
	    }
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends