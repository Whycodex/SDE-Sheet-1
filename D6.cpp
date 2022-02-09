//Find if there is any subarray with sum equal to 0

bool subArrayExists(int arr[], int n)
{
    unordered_set<int>s;
    int presum=0;
    for(int i=0;i<n;i++){
        presum=presum+arr[i];
        if(presum==0)
        return true;
        if(s.find(presum)!=s.end())
        return true;
        if(s.find(presum)==s.end())
        s.insert(presum);
    }
    return false;
}






//Find factorial of a large number

vector<int> factorial(int N){
    vector<int>v;
    v.push_back(1);
    for(int i=2;i<=N;i++){
        int car=0;
        for(int j=0;j<v.size();j++){
            int val=v[j]*i+car;
            v[j]=val%10;
            car=val/10;
        }
        while(car!=0){
            v.push_back(car%10);
            car=car/10;
        }
    }
    reverse(v.begin(),v.end());
    return v;
}






//find maximum product subarray

long long maxProduct(vector<int> arr, int n) {
	long long int maxprod=INT_MIN;
	long long int prod=1;
	for(int i=0;i<n;i++){
	    prod*=arr[i];
	    maxprod=max(maxprod,prod);
	    if(prod==0)
	    prod=1;
	}
	prod=1;
	for(int i=n-1;i>=0;i--){
	    prod*=arr[i];
	    maxprod=max(maxprod,prod);
	    if(prod==0)
	    prod=1;
	}
	return maxprod;
}






//Find longest coinsecutive subsequence

int findLongestConseqSubseq(int arr[], int N)
{
    unordered_set<int>s;
    int res=0;
    for(int i=0;i<N;i++){
        if(s.find(arr[i])==s.end())
        s.insert(arr[i]);
    }
    for(int i=0;i<N;i++){
        if(s.find(arr[i]-1)==s.end()){
            int j=1;
            while(s.find(arr[i]+j)!=s.end()){
                j++;
            }
            res=max(res,j);
        }
    }
    return res;
}