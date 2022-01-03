#include<bits/stdc++.h>
using namespace std;

void sol(int i,int j,int n,int m,vector<vector<int>> &a,vector<vector<int>> &vis,string s){

    if(i<0 || j<0 || i>=n || j>=m || a[i][j]==0 || vis[i][j] == 1){
        return;
    }

    if(i == n-1 && j == m-1){
        cout<<s<<" "<<endl;
        return;
    }
    vis[i][j] = 1;
    sol(i+1,j,n,m,a,vis,s+"D");
    sol(i,j-1,n,m,a,vis,s+"L");
    sol(i,j+1,n,m,a,vis,s+"R");
    sol(i-1,j,n,m,a,vis,s+"U");
    vis[i][j] = 0;
}

void findpath(vector<vector<int>> &a,int n,int m){
    string s = "";
    vector<vector<int>> vis(n,vector<int>(m,0));
    sol(0,0,n,m,a,vis,s);

}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    if(a[0][0] == 1)
        findpath(a,n,m);
    else
        cout<<-1;
return 0;
}


/*
 successfully submited code on gfg  .

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void sol(int i,int j,int n,int m,vector<vector<int>> &a,vector<vector<int>> &vis,string s,
    vector<string> &ans)
    {

        if(i<0 || j<0 || i>=n || j>=m || a[i][j]==0 || vis[i][j] == 1){
            return;
        }
    
        if(i == n-1 && j == m-1){
            ans.push_back(s);
            //cout<<s<<" "<<endl;
            return;
        }
        vis[i][j] = 1;
        sol(i+1,j,n,m,a,vis,s+"D",ans);
        sol(i,j-1,n,m,a,vis,s+"L",ans);
        sol(i,j+1,n,m,a,vis,s+"R",ans);
        sol(i-1,j,n,m,a,vis,s+"U",ans);
        vis[i][j] = 0;
}

    
    vector<string> findPath(vector<vector<int>> &a, int n) {
        // Your code goes here
        int m = a[0].size();
        string s = "";
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<string>ans;
        sol(0,0,n,m,a,vis,s,ans);
        return ans;
    }
};

    



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
*/
