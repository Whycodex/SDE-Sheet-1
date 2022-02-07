//Best time to buy and Sell stock

int maxProfit(vector<int>& prices) {
    int mxprofit=0;
    int minval=INT_MAX;
    for(int i=0;i<prices.size();i++){
        minval=min(minval,prices[i]);
        mxprofit=max(mxprofit,prices[i]-minval);
    }
    return mxprofit;
}






//find all pairs on integer array whose sum is equal to given number

int getPairsCount(int arr[], int n, int k) {
    int count=0;
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        if(m.find(k-arr[i])!=m.end())
        count=count+m[k-arr[i]];
        m[arr[i]]++;
    }
    return count;
}






//find common elements In 3 sorted arrays

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int>v;
    int i=0,j=0,k=0,l=0;
    while(i<n1&&j<n2&&k<n3){
        if(A[i]==B[j]&&B[j]==C[k]&&(v.size()==0||v[l-1]!=A[i])){
            v.push_back(A[i]);
            i++;
            j++;
            k++;
            l++;
        }
        else if(A[i]<B[j]){
            i++;
        }
        else if(B[j]<C[k]){
            j++;
        }
        else{
            k++;
        }
    }
    return v;
}






//Rearrange the array in alternating positive and negative items with O(1) extra space

void rearrange(int arr[], int n) {
	int i=-1,j=n;
	while(true){
	    do{
	        i++;
	    }while(arr[i]>=0);
	    do{
	        j--;
	    }while(arr[j]<0);
	    if(i>=j)
	    break;
	    swap(arr[i],arr[j]);
	}
	int k=1;
	while(k<n&&i<n){
	    swap(arr[k],arr[i]);
	    k=k+2;
	    i++;
	}
}

void rearrange(int arr[], int n) {
	vector<int>v1;
	vector<int>v2;
	for(int i=0;i<n;i++){
	    if(arr[i]>=0)
	    v1.push_back(arr[i]);
	    else
	    v2.push_back(arr[i]);
	}
	int i=0,j=0,k=0;
	while(k<n){
	    if(i<v1.size()){
	        arr[k]=v1[i];
	        i++;
	        k++;
	    }
	    if(j<v2.size()){
	        arr[k]=v2[j];
	        j++;
	        k++;
	    }
	}
}