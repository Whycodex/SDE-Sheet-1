//Minimise the maximum difference between heights [V.IMP]

int getMinDiff(int arr[], int n, int k) {
    sort(arr,arr+n);
    int maxh,minh;
    int res=arr[n-1]-arr[0];
    for(int i=1;i<n;i++){
        maxh=max(arr[n-1]-k,arr[i-1]+k);
        minh=min(arr[0]+k,arr[i]-k);
        if(minh<0)
        continue;
        res=min(res,maxh-minh);
    }
    return res;
}






//Minimum no. of Jumps to reach end of an array
int minJumps(int arr[], int n){
    if(n==1)
    return 0;
    if(arr[0]==0)
    return -1;
    int steps=arr[0];
    int maxreach=arr[0];
    int jumps=1;
    for(int i=1;i<n;i++){
        if(i==n-1)
        return jumps;
        maxreach=max(maxreach,i+arr[i]);
        steps--;
        if(steps==0){
            jumps++;
            if(i>=maxreach)
            return -1;
            steps=maxreach-i;
        }
    }
}






//find duplicate in an array of N+1 Integers

int findDuplicate(vector<int>& nums) {
    int slow=nums[0];
    int fast=nums[nums[0]];
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[nums[fast]];
    }
    slow=0;
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[fast];
    }
    return slow;
}






//Merge 2 sorted arrays without using Extra space.

void merge(int arr1[], int arr2[], int n, int m) {
	int i=n-1,j=0;
	while(i>=0&&j<m){
	    if(arr1[i]>arr2[j])
	    swap(arr1[i],arr2[j]);
	    i--;
	    j++;
	}
	sort(arr1,arr1+n);
	sort(arr2,arr2+m);
}