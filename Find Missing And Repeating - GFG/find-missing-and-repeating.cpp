//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *res=new int[2];
        int xxory=0;
        for(int i=0;i<n;i++){
            xxory^=arr[i];
        }
        for(int i=0;i<n;i++){
            xxory^=(i+1);
        }
        int rsb=xxory&(-xxory);
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if((arr[i]&rsb)==0){
                x^=arr[i];
            }
            else{
                y^=arr[i];
            }
        }
        for(int i=0;i<n;i++){
            if(((i+1)&rsb)==0){
                x^=(i+1);
            }
            else{
                y^=(i+1);
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                res[0]=x;
                res[1]=y;
                break;
            }
            else if(arr[i]==y){
                res[0]=y;
                res[1]=x;
                break;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends