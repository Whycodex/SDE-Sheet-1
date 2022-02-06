//Kadane's Algo [V.V.V.V.V IMP]

long long maxSubarraySum(int arr[], int n){
    int maxsum=arr[0];
    int cursum=arr[0];
    for(int i=1;i<n;i++){
        cursum=max(cursum+arr[i],arr[i]);
        maxsum=max(maxsum,cursum);
    }
    return maxsum;
}






//Merge Intervals

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>>res;
    if(intervals.size()==0)
        return res;
    sort(intervals.begin(),intervals.end());
    vector<int>v=intervals[0];
    for(int i=1;i<intervals.size();i++){
        if(v[1]<intervals[i][0]){
            res.push_back(v);
            v=intervals[i];
        }
        else{
            v[1]=max(v[1],intervals[i][1]);
        }
    }
    res.push_back(v);
    return res;
}






//Next Permutation

void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(),nums.end());
}

void nextPermutation(vector<int>& nums) {
    int firstind=-1,secondind=-1;
    for(int i=nums.size()-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            firstind=i;
            break;
        }
    }
    if(firstind==-1){
        reverse(nums.begin(),nums.end());
        return;
    }
    for(int i=nums.size()-1;i>=0;i--){
        if(nums[i]>nums[firstind]){
            secondind=i;
            break;
        }
    }
    swap(nums[firstind],nums[secondind]);
    reverse(nums.begin()+firstind+1,nums.end());
}






//Count Inversion

long long int merge(long long int arr[],long long int l,long long int mid,long long int r){
    long long int n1=mid-l+1;
    long long int n2=r-mid;
    long long int a[n1];
    long long int b[n2];
    for(long long int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(long long int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }
    long long int i=0,j=0,k=l,count=0;
    while(i<n1&&j<n2){
        if(a[i]<=b[j]){
            arr[k]=a[i];
            i++;
            k++;
        }
        else{
            arr[k]=b[j];
            j++;
            k++;
            count+=n1-i;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=b[j];
        j++;
        k++;
    }
    return count;
}
long long int countmerge(long long int arr[],long long int l,long long int r){
    long long int count=0;
    if(l<r){
        long long int mid=l+(r-l)/2;
        count+=countmerge(arr,l,mid);
        count+=countmerge(arr,mid+1,r);
        count+=merge(arr,l,mid,r);
    }
    return count;
}
long long int inversionCount(long long arr[], long long N)
{
    return countmerge(arr,0,N-1);
}