#include<bits/stdc++.h>
using namespace std;



void sol(int i,int j,int n,int m,vector<vector<int>> &a,vector<vector<int>> &vis,string s,vector<string> &ans,int di[],int dj[],string direction){

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
        sol(i+di[x],j+dj[x],n,m,a,vis,s+direction[x],ans,di,dj,direction);
    }
    vis[i][j] = 0;
}

vector<string> findpath(vector<vector<int>> &a,int n,int m,int di[],int dj[],string direction){
    string s = "";
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<string> ans;
    sol(0,0,n,m,a,vis,s,ans,di,dj,direction);
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
    int di[] = {1,0,0,-1};
    int dj[] = {0,-1,1,0};
    string direction = "DLRU";

    vector<string> result =  findpath(a,n,m,di,dj,direction);

    if(result.size() == 0) cout<<-1<<endl;   
    else
        for(int i = 0;i<result.size();i++){
            cout<<result[i]<<" ";
        }
    cout<<endl;
return 0;
}