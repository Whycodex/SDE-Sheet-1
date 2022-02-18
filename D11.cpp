//Print elements in sorted order using row-column wise sorted matrix

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
    vector<vector<int>>res;
    vector<int>v;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            v.push_back(Mat[i][j]);
        }
    }
    sort(v.begin(),v.end());
    int idx=0;
    for(int i=0;i<N;i++){
        vector<int>temp;
        for(int j=0;j<N;j++){
            temp.push_back(v[idx]);
            idx++;
        }
        res.push_back(temp);
    }
    return res;
}






//Maximum size rectangle

int largesthistogram(int arr[],int n){
    int res=0;
    stack<int>s;
    int ps[n],ns[n];
    for(int i=0;i<n;i++){
        while(s.empty()==false&&arr[s.top()]>=arr[i]){
            s.pop();
        }
        ps[i]=s.empty()?0:s.top()+1;
        s.push(i);
    }
    while(s.empty()==false){
        s.pop();
    }
    for(int i=n-1;i>=0;i--){
        while(s.empty()==false&&arr[s.top()]>=arr[i]){
            s.pop();
        }
        ns[i]=s.empty()?n-1:s.top()-1;
        s.push(i);
    }
    for(int i=0;i<n;i++){
        res=max(res,(ns[i]-ps[i]+1)*arr[i]);
    }
    return res;
}
int maxArea(int M[MAX][MAX], int n, int m) {
    int res=largesthistogram(M[0],m);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j]==1)
            M[i][j]+=M[i-1][j];
            else
            M[i][j]=0;
        }
        int temp=largesthistogram(M[i],m);
        res=max(res,temp);
    }
    return res;
}






//Find a specific pair in matrix

int findmax(int mat[][],int n,int m){
    int maxi=INT_MIN;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            for(int k=i+1;k<n;k++){
                for(int l=j+1;l<n;l++){
                    maxi=max(maxi,mat[k][l]-mat[i][j]);
                }
            }
        }
    }
    return maxi;
}






//Rotate matrix by 90 degrees

void rotate(int mat[][],int n,int m){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<m;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        int low=0,high=m-1;
        while(low<high){
            swap(mat[low][i],mat[high][i]);
            low++;
            high--;
        }
    }
}