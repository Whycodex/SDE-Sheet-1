//Move all the negative elements to one side of the array 

void Rearrange(int arr[], int n)
{
    // Your code goes here
    vector<int>v1;
    vector<int>v2;
    for(int i=0;i<n;i++){
        if(arr[i]<0)
        v1.push_back(arr[i]);
        else
        v2.push_back(arr[i]);
    }
    int i=0,j=0;
    while(i<v1.size()){
        arr[i]=v1[i];
        i++;
    }
    while(j<v2.size()){
        arr[i]=v2[j];
        i++;
        j++;
    }
}






//Find the Union and Intersection of the two sorted arrays
int doUnion(int a[], int n, int b[], int m)  {
        //code here
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            if(s.find(a[i])==s.end())
            s.insert(a[i]);
        }
        for(int i=0;i<m;i++){
            if(s.find(b[i])==s.end())
            s.insert(b[i]);
        }
        return s.size();
    }






//Write a program to cyclically rotate an array by one

void rotate(int arr[], int n)
{
    int temp=arr[n-1];
    for(int i=n-1;i>=0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=temp;
}






//find Largest sum contiguous Subarray [V. IMP]

long long maxSubarraySum(int arr[], int n){
    
    int totalsum=arr[0];
    int cursum=arr[0];
    for(int i=1;i<n;i++){
        cursum=max(cursum+arr[i],arr[i]);
        totalsum=max(totalsum,cursum);
    }
    return totalsum;
}