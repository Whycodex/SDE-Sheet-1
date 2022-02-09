//Given an array of size n and a number k, find all elements that appear more than n/k times

vector<int>printnbyk(vector<int>arr,int n,int k){
    vector<int>v;
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    for(auto i:m){
        if(i.second>n/k)
        v.push_back(i.first);
    }
    return v;
}






//Maximum profit by buying and selling a share atmost twice

int maxprofit(vetor<int>arr,int n){
    vector<int>v(n);
    int maxi=arr[n-1];
    for(int i=n-2;i>=0;i--){
        if(arr[i]>maxi)
        maxi=arr[i];
        v[i]=max(v[i+1],maxi-arr[i]);
    }
    int mini=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<mini)
        mini=arr[i];
        v[i]=max(v[i-1],v[i]+(arr[i]-mini));
    }
    return v[n-1];
}






//Find whether an array is a subset of another array

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_set<int>s;
    for(int i=0;i<n;i++){
        if(s.find(a1[i])==s.end())
        s.insert(a1[i]);
    }
    for(int i=0;i<m;i++){
        if(s.find(a2[i])==s.end())
        return "No";
    }
    return "Yes";
}






//Find the triplet that sum to a given value

bool check(int arr[],int i,int j,int x){
    while(i<j){
        if(arr[i]+arr[j]==x)
        return true;
        else if(arr[i]+arr[j]<x)
        i++;
        else
        j--;
    }
    return false;
}
bool find3Numbers(int A[], int n, int X)
{
    sort(A,A+n);
    for(int i=0;i<n;i++){
        if(check(A,i+1,n-1,X-A[i])==true)
        return true;
        }
    return false;
}