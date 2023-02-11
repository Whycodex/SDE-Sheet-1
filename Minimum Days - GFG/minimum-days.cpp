//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int getMinimumDays(int N,string S, vector<int> &P) {
        // code here
        int res=0;
        for(int i=0;i<N-1;i++){
            if(S[i]==S[i+1]){
                res++;
            }
        }
        if(res==0){
            return 0;
        }
        for(int i=0;i<N;i++){
            int j=P[i];
            if(j+1<N&&S[j]==S[j+1]){
                res--;
            }
            if(j>=0&&S[j-1]==S[j]){
                res--;
            }
            S[j]='?';
            if(res==0){
                return i+1;
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends