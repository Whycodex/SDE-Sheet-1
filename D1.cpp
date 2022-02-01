//Reverse the array

string reverseWord(string str){
    reverse(str.begin(),str.end());
    return str;
}

void reverseArray(int arr[],int n){
    for(int i=0,j=n-1;i<j;i++,j--){
        swap(arr[i],arr[j]);
    }
}






//Find the maximum and minimum element in an array

pair<long long, long long> getMinMax(long long a[], int n) {
    long long int minVal=INT_MAX,maxVal=INT_MIN;
    for(int i=0;i<n;i++){
        minVal=min(minVal,a[i]);
        maxVal=max(maxVal,a[i]);
    }
    return {minVal,maxVal};
}






//Find the "Kth" max and min element of an array 

int kthSmallest(int arr[], int l, int r, int k) {
    sort(arr,arr+r+1);
    return arr[k-1];
}






//Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo

void sort012(int a[], int n)
{
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(a[mid]==0){
            swap(a[mid],a[low]);
            low++;
            mid++;
        }
        else if(a[mid]==1){
            mid++;
        }
        else{
            swap(a[mid],a[high]);
            high--;
        }
    }
}