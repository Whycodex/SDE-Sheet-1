//Trapping Rain water problem

long long trappingWater(int arr[], int n){
    long long int res=0;
    int lmax[n],rmax[n];
    lmax[0]=arr[0];
    int leftm=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>leftm){
            leftm=arr[i];
        }
        lmax[i]=leftm;
    }
    rmax[n-1]=arr[n-1];
    int rightm=arr[n-1];
    for(int i=n-2;i>=0;i--){
        if(arr[i]>rightm){
            rightm=arr[i];
        }
        rmax[i]=rightm;
    }
    for(int i=1;i<n-1;i++){
        res=res+(min(lmax[i],rmax[i])-arr[i]);
    }
    return res;
}






//Chocolate Distribution problem

long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(),a.end());
    long long int res=INT_MAX;
    for(long long int i=0;i<n-m+1;i++){
        res=min(res,a[i+m-1]-a[i]);
    }
    return res;
}






//Smallest Subarray with sum greater than a given value

int smallestsubarray(vector<int>arr,int x){
    int res=INT_MAX;
    int start=0,end=0;
    int cursum=0;
    while(end<arr.size()){
        cursum=cursum+arr[i];
        while(cursum>=x){
            res=min(res,end-start+1);
            cursum=cursum-arr[i];
            start++;
        }
        end++;
    }
    return res;
}






//Three way partitioning of an array around a given value

void threeWayPartition(vector<int>& array,int a, int b)
{
    int low=0,mid=0,high=array.size()-1;
    while(mid<=high){
        if(array[mid]<a){
            swap(array[mid],array[low]);
            low++;
            mid++;
        }
        else if(array[mid]>=a&&array[mid]<=b){
            mid++;
        }
        else if(array[mid]>b){
            swap(array[mid],array[high]);
            high--;
        }
    }
}