//Minimum swaps required bring elements less equal K together

int minSwap(int arr[], int n, int k) {
    int count=0;
    int f=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=k)
        count++;
    }
    for(int i=0;i<count;i++){
        if(arr[i]>k)
        f++;
    }
    int res=f;
    for(int i=0,j=count;j<n;i++,j++){
        if(arr[i]>k)
        f--;
        if(arr[j]>k)
        f++;
        res=min(res,f);
    }
    return res;
}






//Minimum no. of operations required to make an array palindrome

int palindrome(vector<int>v){
    int res=0;
    int i=0,j=v.size()-1;
    while(i<j){
        if(v[i]==v[j]){
            i++;
            j--;
        }
        else if(v[i]>v[j]){
            j--;
            v[j]=v[j]+v[j+1];
            res++;
        }
        else{
            i++;
            v[i]=v[i]+v[i-1];
            res++;
        }
    }
    return res;
}






//Median of 2 sorted arrays of equal size

int median(vector<int>&v1,vector<int>&v2){
    vector<int>v;
    int i=0,j=0;
    while(i<v1.size()&&j<v2.size()){
        if(v1[i]<=v2[j]){
            v.push_back(v1[i]);
            i++;
        }
        else{
            v.push_back(v2[j])
            j++;
        }
    }
    while(i<v1.size()){
        v.push_back(v1[i]);
        i++;
    }
    while(j<v2.size()){
        v.push_back(v2[j]);
        j++;
    }
    if((v1.size()+v2.size())%2==0){
        int mid1=v.size()/2;
        int mid2=(v.size()/2)+1;
        return v[(mid1+mid2)/2];
    }
    else{
        return v[(v.size()+1)/2];
    }
}






//Median of 2 sorted arrays of different size

int differentmedian(vector<int>&nums1,vector<int>&nums2){
    int n1=nums1.size(),n2=nums2.size();
    if(n2<n1)
    return differentmedian(nums2,nums1);
    int low=0,high=n1;
    while(low<=high){
        int cut1=(low+high)/2;
        int cut2=((low+mid)+1)/2-cut1;
        int left1=(cut1==0)?INT_MIN:nums1[cut1-1];
        int left2=(cut2==0)?INT_MIN:nums2[cut2-1];
        int right1=(cut1==n1)?INT_MAX:nums1[cut1];
        int right2=(cut2==n2)?INT_MAX:nums2[cut2];
        if(left1<=right2&&left2<=right1){
            if(n1+n2%2==0)
            return (max(left1,left2)+min(right1,right2)+1)/2;
            else
            return max(left1,left2);
        }
        else if(left1<right2){
            high=cut1-1;
        }
        else{
            low=cut1+1;
        }
    }
    return 0;
}