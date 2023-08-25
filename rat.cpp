
#include<bits/stdc++.h>
using namespace std;
vector<string>ans;
void find(int i,int j,int n,vector<vector<int>>&m,string s,vector<vector<int>>&vis){
    // cout<<i<<" "<<j<<" ";
    if(i<0||i>=n||j<0||j>=n||m[i][j]==0||vis[i][j]==1){
        return;
    }
    if(i==n-1&&j==n-1){
        ans.push_back(s);
        return;
    }
    vis[i][j]=1;
    find(i-1,j,n,m,s+'U',vis);
    find(i,j+1,n,m,s+'R',vis);
    find(i+1,j,n,m,s+'D',vis);
    find(i,j-1,n,m,s+'L',vis);
    vis[i][j]=0;
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    if(m[0][0]==0||m[n-1][n-1]==0)return {"-1"};
    vector<vector<int>>vis(n,vector<int>(n,0));
    find(0,0,n,m,"",vis);
    return ans;
}
int main() {
	int  n;
	cin >> n;
	vector<vector<int>>maze(18,vector<int>(18,0));
	for(int i=0; i<n ; i++){
		for(int  j=0 ; j<n ; j++){
            int x;
			cin >>x;
            maze[i][j]=x;
		}
	}
	vector<string>x=findPath(maze,n);
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<" ";
    }
	return 0;
}