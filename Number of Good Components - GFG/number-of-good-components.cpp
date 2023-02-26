//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool helper(vector<vector<int>>&adj,int node,int &n,int vis[]){
        vis[node]=1;
        bool flag=true;
        n++;
        for(auto i:adj[node]){
            if(!vis[i]){
                flag=flag&helper(adj,i,n,vis);
            }
        }
        if(adj[node].size()!=n-1){
            return false;
        }
        else{
            return flag;
        }
    }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        int vis[V+1]={0};
        int count=0;
        for(int i=1;i<=V;i++){
            int n=0;
            if(!vis[i]){
                if(helper(adj,i,n,vis)==true){
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends