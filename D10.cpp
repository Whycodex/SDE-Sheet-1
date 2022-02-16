//Spiral traversal on a Matrix

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
{
    vector<int>v;
    int top=0,left=0,bottom=r-1,right=c-1;
    while(top<=bottom&&left<=right){
        for(int i=left;i<=right;i++){
            v.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            v.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                v.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                v.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return v;
}






//Search an element in a matriix

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int i=0,j=matrix[0].size()-1;
    while(i<matrix.size()&&j>=0){
        if(matrix[i][j]==target)
            return true;
        else if(matrix[i][j]<target)
            i++;
        else
            j--;
    }
    return false;
}






//Find median in a row wise sorted matrix

int median(vector<vector<int>> &matrix, int r, int c){     
    vector<int>v;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            v.push_back(matrix[i][j]);
        }
    }
    sort(v.begin(),v.end());
    return v[(v.size())/2];
}

int countlessorequal(vector<int>&v,int target){
    int low=0,high=v.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(v[mid]<=target)
        low=mid+1;
        else
        high=mid-1;
    }
    return low;
}
int median(vector<vector<int>> &matrix, int r, int c){   
    int low=INT_MAX,high=INT_MIN;
    for(int i=0;i<r;i++){
        low=min(low,matrix[i][0]);
        high=max(high,matrix[i][c-1]);
    }
    while(low<=high){
        int mid=(low+high)/2;
        int count=0;
        for(int i=0;i<r;i++){
            count+=countlessorequal(matrix[i],mid);
        }
        if(count<=(r*c)/2)
        low=mid+1;
        else
        high=mid-1;
    }
    return low;
}






//Find row with maximum no. of 1's

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	int i=0,j=m-1;
	int res=-1;
	while(i<n&&j>=0){
	    if(arr[i][j]==1){
	        j--;
	        res=i;
	    }
	    else{
	        i++;
	    }
	}
	return res;
}