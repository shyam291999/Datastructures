#include<bits/stdc++.h>
using namespace std;

int di[] = {1,0,0,-1};
int dj[] = {0,-1,1,0};
string direction = "DLRU";

void sol(int i,int j,int n,int m,vector<vector<int>> &a,vector<vector<int>> &vis,string s,vector<string> &ans){

    //visited of i,j should not be visited preciously because it will form a cycle;
    if(i<0 || j<0 || i>=n || j>=m || a[i][j]==0 || vis[i][j] == 1){
        return;
    }

    if(i == n-1 && j == m-1){
        //cout<<s<<" "<<endl;
        ans.push_back(s);
        return;
    }
    vis[i][j] = 1;
    for(int x = 0;x<4;x++){
        sol(i+di[x],j+dj[x],n,m,a,vis,s+direction[x],ans);
    }
    vis[i][j] = 0;
}

vector<string> findpath(vector<vector<int>> &a,int n,int m){
    string s = "";
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<string> ans;
    sol(0,0,n,m,a,vis,s,ans);
    return ans;

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

    vector<string> result =  findpath(a,n,m);

    if(result.size() == 0) cout<<-1<<endl;   
    else
        for(int i = 0;i<result.size();i++){
            cout<<result[i];
        }
    cout<<endl;
return 0;
}




/*

// successfully submitedss code at gfg
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    int di[4] = {1,0,0,-1};
    int dj[4] = {0,-1,1,0};
    string direction = "DLRU";
    
    void sol(int i,int j,int n,int m,vector<vector<int>> &a,vector<vector<int>> &vis,string s,vector<string> &ans){

    //visited of i,j should not be visited preciously because it will form a cycle;
    if(i<0 || j<0 || i>=n || j>=m || a[i][j]==0 || vis[i][j] == 1){
        return;
    }

    if(i == n-1 && j == m-1){
        ans.push_back(s);
        return;
    }
    vis[i][j] = 1;
    for(int x = 0;x<4;x++){
        sol(i+di[x],j+dj[x],n,m,a,vis,s+direction[x],ans);
    }
    vis[i][j] = 0;
}
    
    vector<string> findPath(vector<vector<int>> &a, int n) {
        // Your code goes here
        int m = a[0].size();
        string s = "";
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<string> ans;
        sol(0,0,n,m,a,vis,s,ans);
        return ans;
    }
};

    


// { Driver Code Starts.

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