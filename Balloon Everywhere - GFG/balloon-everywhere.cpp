//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++){
            if(s[i]=='b'||s[i]=='a'||s[i]=='l'||s[i]=='o'||s[i]=='n'){
                m[s[i]]++;
            }
        }
        for(auto i:m){
            if(i.first=='l'){
                m[i.first]=(i.second/2);
                if(m[i.first]==0){
                    m.erase(m[i.first]);
                }
                break;
            }
        }
        for(auto i:m){
            if(i.first=='o'){
                m[i.first]=(i.second/2);
                if(m[i.first]==0){
                    m.erase(m[i.first]);
                }
                break;
            }
        }
        int res=INT_MAX;
        for(auto i:m){
            res=min(res,i.second);
        }
        if(m.size()<5){
            return 0;
        }
        else{
            return res;
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends